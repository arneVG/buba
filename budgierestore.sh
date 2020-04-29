#!/bin/sh

mkdir -p ~/budgiebackup/

tar -xzvf budgiebackup.tar.gz

dconf load /com/solus-project/ < ~/budgiebackup/budgie-dconf-dump

rm -R ~/budgiebackup/