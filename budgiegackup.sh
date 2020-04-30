#!/bin/sh

usage() {
    echo "usage: ./budgiebackup.sh [args] <filename>";
    echo "args:";
    echo "  -c  create a backup";
    echo "  -r  restore a backup";
    exit 0;
}

create() {
    mkdir -p ~/.budgiebackup
    dconf dump /com/solus-project/ > ~/.budgiebackup/budgie-dconf-dump
    tar -czvf $1 -C ~/.budgiebackup .
    rm -R ~/.budgiebackup/
    exit 1;
}

restore() {
    mkdir -p ~/.budgiebackup/
    tar -C ~/.budgiebackup -xzvf $1
    dconf load /com/solus-project/ < ~/.budgiebackup/budgie-dconf-dump
    rm -R ~/.budgiebackup/
    exit 1;
}

while getopts ":hc:r:" o; do
    case "${o}" in
        c)
            create $OPTARG
            ;;
        r)
            restore $OPTARG
            ;;
        h)
            usage
            ;;
    esac
done