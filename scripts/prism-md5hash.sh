#!/bin/bash
echo MD5 hash of "$1" is:
printf '%s' "$1" | md5sum
