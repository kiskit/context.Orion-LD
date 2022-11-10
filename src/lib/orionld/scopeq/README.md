## TODO
* Check/Analysis of scope in entity
* Scopeq filter may go in other cases
* bson construction could be better but beats me how to do it
* bson destroy where they are needed
* a scope given without a leading '/' will be "corrected"
## Test cases


### Should be working
* Madrid
* /Madrid
* /Madrid_
* /Madrid42
* Madrid/Princesa
* /Madrid/Princesa
* /Madrid/#
* /#
* /Madrid/+/Parque
* /Madrid/+

### Should not be working

* /Madrid/
* Madrid/
* /42
* /_
* \#
* /Madrid/#/Parque