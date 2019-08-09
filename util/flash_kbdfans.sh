#!/bin/bash
dfu-util --list
dfu-util -a 0 -d 0483:df11 -s 0x08000000:leave --download $1