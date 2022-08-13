#!/bin/bash

mkdir -p vendor

cd ./vendor

# Download Pico SDK
git clone -b master https://github.com/raspberrypi/pico-sdk.git

cd pico-sdk

git submodule update --init