#!/bin/sh

mkdir -p ~/budgiebackup

dconf dump /com/solus-project/ > ~/budgiebackup/budgie-dconf-dump

tar -czvf budgiebackup.tar.gz budgiebackup/

rm -R ~/budgiebackup/