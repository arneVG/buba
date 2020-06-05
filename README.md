# buba

Vala program for backing up and restoring budgie configs

## dependencies

- dconf

## notes

Only makes a backup of the configurations. Doesn't make backups of themes, applets or plank configs

## usage

```shell
./buba [args] <filename>
 args:
  -c  create a backup
  -r  restore a backup
