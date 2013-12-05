#!/bin/sh

/opt/qemu/bin/qemu-system-arm -M vexpress-a9 -cpu cortex-a9 -m 128 -nographic -kernel bin/qernel.img
