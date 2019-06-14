#!/usr/bin/env python

from __future__ import print_function

import ConfigParser
import os

class Huch(object):
    def __init__(self):
        self.c = ConfigParser.RawConfigParser()
        self.cfg_filename = 'cfg_tmp.txt'
        self.some_list = ['a', 'b', 'c']

    def read(self):
        if os.path.isfile(self.cfg_filename):  # actually, if file exists, and is read and writeable
            try:
                self.c.read(self.cfg_filename)
                print('INFO: all good')
            except ConfigParser.Error, err:
                print("ERROR: ", err)
                raise err
        else:
            print('INFO: creating new file: ', self.cfg_filename)

            # TODO: assume, that the file does not exists, so let's just create it
            for s in self.some_list:
                self.c.add_section(s)
                self.c.set(s, 'last_updated', 0)
                # ... add more items

            with open(self.cfg_filename, 'w') as cfgfile:
                self.c.write(cfgfile)

            self.read()


    def show(self):
        for s in self.some_list:
            x = self.c.get(s, 'last_updated')
            print('Section "', s, '" was last updated: ', x)


def main():
    h = Huch()
    h.read()
    h.show()


if __name__ == '__main__':
    main()


