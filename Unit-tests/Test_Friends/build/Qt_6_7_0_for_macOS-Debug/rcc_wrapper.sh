#!/bin/bash
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
exec /Users/emirmiskevich/Qt/6.7.0/macos/libexec/rcc "$@"
