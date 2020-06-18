from os.path import expanduser, exists
from os import walk, makedirs

def get_config_dir():
    home_dir = expanduser("~")
    config_dir = home_dir + "/.config/buba/"
    if not exists(config_dir):
        makedirs(config_dir)
    return config_dir

def list_files():
    dir = get_config_dir()
    files = []
    for (dirpath, dirnames, filenames) in walk(dir):
        files.extend(filenames)
        break
    files.sort()
    return files