#!/bin/bash
find . -iname "*.sh" | sed "s/.*\///; s/\.sh//"
