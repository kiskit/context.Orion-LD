# Orion-LD Installation Guide for Debian 10.6 netinst

In order to write this guide, Debian 10.6 (netinst image) was downloaded from [here](https://www.debian.org/distrib/netinst) (Small CDs or USB sticks - amd64),
and installed as a virtual machine under VMWare.

## This Guide is out of date
What's missing is stuff about postgres and prometheus-client-c.
Well, and a general cleanup to follow the new "design" of the Ubuntu guides.
For now, no further work on this installation guide is planned - unless we receive complaints. If so, time will be allocated for an update.
Anyway, Ubuntu and Debian are related, so, it shouldn't be too hard to use an Ubuntu guide and some googling to finish the installation.

## Distro Installation
During OS installation, when asked for "Software selection", I ticked:
* Debian desktop environment
* GNOME
* SSH server
* standard system utilities

To be able to install packages, you need to make sure your user can use the `sudo` command.
If you already have "sudo privileges" (I did not, right after installation - other distros give the user sudo provileges) you can skip the following instructions.

## Sudo Privileges
There are more than one way to accomplish "sudo privileges".
I use the following way:

As you don't have sudo privileges, you need to enter as root and edit the file `/etc/sudoers`:
```bash
% su
# vi /etc/sudoers
```

Assuming your user is 'X', after the lines
```bash
# User privilege specification
root   ALL=(ALL:ALL) ALL
```

add the line
```bash
X     ALL=(ALL:ALL) ALL
```

Save the file and quit the editor.
Exit as root and make sure `sudo` now works:
```bash
$ sudo ls
```

## Update the Installation
Now, to get the latest version of all installed packages, once the installation is done, log in, open a terminal and issue the following command:
```bash
sudo apt-get update
sudo apt-get upgrade
```

## Installation of dependency packages

Now, a whole bunch of packages are to be installed. Personally I prefer *aptitude* over *apt-get*, so the first thing I do is to install *aptitude*:

```bash
sudo apt-get install aptitude
```

Tools needed for compilation and testing:

```bash
sudo aptitude install build-essential cmake scons curl
```

Libraries that aren't built from source code:

```bash
sudo aptitude install libssl-dev gnutls-dev libcurl4-gnutls-dev libsasl2-dev \
                      libgcrypt-dev uuid-dev libboost-dev libboost-regex-dev libboost-thread-dev \
                      libboost-filesystem-dev libz-dev libmongoclient-dev
```

## Download and build dependency libraries from source code
Some libraries are built from source code and those sources must be downloaded and compiled.
* libmicrohttpd:  0.9.72
* rapidjson:      1.0.2
* kbase:          0.5
* klog:           0.5
* kalloc:         0.5
* kjson:          0.5
* khash:          0.5
* gtest:          1.5 (needed for unit testing only)
* gmock:          1.5 (needed for unit testing only)

For those libraries that are cloned repositories, I myself keep all repositories in a directory I call *git* directly under my home directory: `~/git`.
This guide follows that example, so, let's start by creating the directory for repositories:

```bash
mkdir ~/git
```

And, as `git` will be used, we might as well install it right away:

```bash
sudo aptitude install git
```

### User and Group
Many of the following commands need a change in ownership - you need to maker yourself owner of the file.
For this we will use the `chown` command and `chown` need your user and group id as input.
Your user id is already knowd via the environment variable `USER`.
Check it like this:
```bash
% echo $USER
```

But, you need also your group id.
Most distros (debian included) creates a group for you with the same name as your user id.
Check this by issuing the `id` command.

This is my output of the `id` command:
```bash
% id
uid=1001(kz) gid=1001(kz) groups=1001(kz),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),118(lpadmin),126(sambashare),999(docker)
```

You can see that my group id is 1001 (`gid=1001(kz)`) and the group name is `kz`.

So, in order to be able to just copy-paste the commands in this guide, you need to create an environment variable for your GROUP.

In my case it looks like this:
```bash
% export GROUP=kz
```

Later on, this new environment variable will be used to make yourself the owner of files, something like this:
```bash
% sudo chown $USER:$GROUP /usr/bin/orionld
```
_(Don't issue that command - it is just an example and it will fail as /usr/bin/orionld still hasn't been built)_

### libmicrohttpd

*libmicrohttpd* is the library that takes care of incoming connections and http/https.
This is how you install libmicrohttpd from source code:

```bash
sudo mkdir /opt/libmicrohttpd
sudo chown $USER:$GROUP /opt/libmicrohttpd
cd /opt/libmicrohttpd
wget http://ftp.gnu.org/gnu/libmicrohttpd/libmicrohttpd-0.9.72.tar.gz
tar xvf libmicrohttpd-0.9.72.tar.gz
cd libmicrohttpd-0.9.72
./configure --disable-messages --disable-postprocessor --disable-dauth
make
sudo make install
```

### rapidjson

*rapidjson* is the JSON parser used by the NGSI APIv2 implementation.
AS Orion-LD includes NGSI APIv2 as well, we need this library.
We use an older version of the library.
This is	how to install it from source code:

```bash
sudo mkdir /opt/rapidjson
sudo chown $USER:$GROUP /opt/rapidjson
cd /opt/rapidjson
wget https://github.com/miloyip/rapidjson/archive/v1.0.2.tar.gz
tar xfvz v1.0.2.tar.gz
sudo mv rapidjson-1.0.2/include/rapidjson/ /usr/local/include
```

```bash
cd ~/git
git clone https://gitlab.com/kzangeli/kbase.git
cd kbase
git checkout release/0.5
make install
```

### klog

*klog* is a library for logging, used by the rest of the "K-libs".
To download, build and install:

```bash
cd ~/git
git clone https://gitlab.com/kzangeli/klog.git
cd klog
git checkout release/0.5
make install
```


### kalloc

*kalloc* is a library that provides faster allocation by avoiding calls to `malloc`.
The library allocates *big* buffers by calling `malloc` and then gives out portions of this big allocated buffer.
The portions cannot be freed, only the *big* buffers allocated via `malloc` and that is done when the kalloc instance dies.
For a context broker, that treats every request in a separate thread, this is ideal from a performance point of view.

To download, build and install:
```bash
cd ~/git
git clone https://gitlab.com/kzangeli/kalloc.git
cd kalloc
git checkout release/0.5
make install
```

### kjson

*kjson* is a JSON parser that builds a simple-to-use KjNode tree from the textual JSON input.
It is very easy to use (linked lists) and many times faster than rapidjson, which APIv2 uses.
The new implementation for NGSI-LD uses `kjson` instead of rapidjson.

To download, build and install:
```bash
cd ~/git
git clone https://gitlab.com/kzangeli/kjson.git
cd kjson
git checkout release/0.5
make install
```

### khash

*khash* is a library that provides a hash table implementation. This hash table is used for the Context Cache of Orion-LD.

To download, build and install:
```bash
cd ~/git
git clone https://gitlab.com/kzangeli/khash.git
cd khash
git checkout release/0.5
make install
```

### MQTT (Paho & Mosquitto)

*MQTT* is a machine-to-machine (M2M)/"Internet of Things" connectivity protocol. It was designed as an extremely lightweight publish/subscribe messaging transport. It is useful for connections with remote locations where a small code footprint is required and/or network bandwidth is at a premium. Source: https://mqtt.org

To download, build and install:

#### Eclipse Paho

The *Eclipse Paho* project provides open-source client implementations of MQTT and MQTT-SN messaging protocols aimed at new, existing, and emerging applications for the Internet of Things (IoT). Source: https://www.eclipse.org/paho

```bash
sudo aptitude install doxygen
sudo aptitude install graphviz
sudo rm -f /usr/local/lib/libpaho*
cd ~/git
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
git fetch -a
git checkout tags/v1.3.1
make html
make
sudo make install

# Python library
sudo apt install python-pip
pip install paho-mqtt
```

#### Eclipse Mosquitto

*Eclipse Mosquitto* is an open source (EPL/EDL licensed) message broker that implements the MQTT protocol versions 5.0, 3.1.1 and 3.1. Mosquitto is lightweight and is suitable for use on all devices from low power single board computers to full servers. Source: https://mosquitto.org

```bash
sudo aptitude install mosquitto
sudo systemctl start mosquitto

# If you wish to enable `mosquitto` to have it start automatically on system reboot:
# [ If you prefer to use another MQTT broker, that's fine too. But, bear in mind that only mosquitto has been tested ]
sudo systemctl enable mosquitto
```

## Source code of Orion-LD

Now that we have all the dependencies installed, it's time to clone the Orion-LD repository:

```bash
cd ~/git
git clone https://github.com/FIWARE/context.Orion-LD.git
cd context.Orion-LD
```

At the end of `make install`, the makefile wants to copy the executable (orionld) to /usr/bin, and more files under /usr.
Unless we do something, this will fail, as privileges are needed to create/modify files in system directories.
What we will do is to create the files by hand, using `sudo` and then set ourselves as owner of the files.
For this you will use `chown`and the GROUP environment variable previously created:

```bash
sudo touch /usr/bin/orionld
sudo chown $USER:$GROUP /usr/bin/orionld
sudo touch /etc/init.d/orionld
sudo chown $USER:$GROUP /etc/init.d/orionld
sudo touch /etc/default/orionld
sudo chown $USER:$GROUP /etc/default/orionld
```
And finally we can compile the broker:
```bash
make install
```

You now have *orionld*, the NGSI-LD Context Broker compiled, installed and ready to work :)

Except, of course, you need to install the MongoDB server as well.
So far, we have only installed the mongo client library, so that *orionld* can speak to the MongoDB server.

## Install the MongoDB server
If using a docker image, the MongoDB server comes as part of the docker, but if docker is not used, then the MongoDB server must be installed.
For this, please refer to the [MongoDB documentation](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-debian/).
The version 4.4 is recommended for Debian 10.6, but older version might work as well.

This is what the MongoDB documentation tells us to do to install MongoDB server 4.4 under Debian 10:

```bash
# Import the MongoDB public GPG Key
wget -qO - https://www.mongodb.org/static/pgp/server-4.4.asc | sudo apt-key add -
# Should respond with "OK"

# Create the list file /etc/apt/sources.list.d/mongodb-org-4.0.list
echo "deb http://repo.mongodb.org/apt/debian buster/mongodb-org/4.4 main" | sudo tee /etc/apt/sources.list.d/mongodb-org-4.4.list

# Reload local package database
sudo aptitude update

# Install the MongoDB packages
sudo aptitude install -y mongodb-org

# Start the mongodb daemon
sudo systemctl start mongod

# Ensure that MongoDB will start following a system reboot
sudo systemctl enable mongod
```

For more detail on the MongoDB installation process, or if something goes wrong, please refer to the [MongoDB documentation](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-debian/)
