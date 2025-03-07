#!/usr/bin/python
# -*- coding: latin-1 -*-
# Copyright 2013 Telefonica Investigacion y Desarrollo, S.A.U
#
# This file is part of Orion Context Broker.
#
# Orion Context Broker is free software: you can redistribute it and/or
# modify it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# Orion Context Broker is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
# General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with Orion Context Broker. If not, see http://www.gnu.org/licenses/.
#
# For those usages not covered by this license please contact with
# iot_support at tid dot es

from optparse import OptionParser
from re import match
from os.path import exists


def validation_error(input_line, ref_line):
    print("VALIDATION ERROR: input line:")
    print("   " + input_line)
    print("does not match ref line:")
    print("   " + ref_line)
    exit(1)


def line_count(file_name):
    input_file = open(file_name, 'r')
    lines = 0

    for _ in input_file.readlines():
        lines = lines + 1

    input_file.close()
    return lines


def escape(s):
    # Maybe some other "regex sensible" chars need to be escaped... this function will be
    # adjusted in that case
    return s.replace('[', r'\[').replace(']', r'\]').replace('{', r'\{').replace('}', r'\}').replace('?', r'\?')


def diff_files(input_file, ref_file):

    input_file = open(input_file, 'r')
    ref = open(ref_file, 'r')

    input_lines = input_file.readlines()

    for ref_line in ref.readlines():
        # Get line from input file
        try:
            input_line = input_lines.pop(0)

            # Removing trailing whitespace(to avoid "noisy" input/reference files)
            ref_line = ref_line.rstrip()
            input_line = input_line.rstrip()

            # Check if normal line or regex(using regex itself
            m = match(r'(.*)REGEX\((.*)\)(.*)', ref_line)
            if m is not None:
                # We build the regex, concatenating preamble,
                # regex expression itself and the last part
                regex = escape(m.group(1)) + m.group(2) + escape(m.group(3))

                if not match(regex, input_line):
                    validation_error(input_line, ref_line)
            else:
                if not ref_line == input_line:
                    validation_error(input_line, ref_line)
        except IndexError:
            print("VALIDATION ERROR: input file has less lines than reference")
            exit(1)

    print("Validation ok")
    exit(0)


def main():
    parser = OptionParser()
    parser.add_option("-i", "--input", dest="input_file",
                      help="Input file to be tested")
    parser.add_option("-r", "--reference", dest="ref_file",
                      help="Reference file to be used as a comparison")
    (options, args) = parser.parse_args()

    if not options.input_file:
        parser.error("Missing input file")
    else:
        if not exists(options.input_file):
            parser.error("Input file %s does not exist" % options.input_file)

    if not options.ref_file:
        parser.error("Missing test file")
    else:
        if not exists(options.ref_file):
            parser.error("Reference file %s does not exist" % options.ref_file)

    i_lines = line_count(options.input_file)
    r_lines = line_count(options.ref_file)

    if i_lines == 0:
        print("VALIDATION ERROR: input file is EMPTY")
        exit(1)

    if r_lines == 0:
        print("VALIDATION ERROR: reference file is EMPTY")
        exit(1)

    if not i_lines == r_lines:
        print("VALIDATION ERROR: input file and reference file have different line count")
        exit(1)

    diff_files(options.input_file, options.ref_file)


if __name__ == "__main__":
    main()
