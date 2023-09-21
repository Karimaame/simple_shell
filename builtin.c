#include "shell.h"

int _myexit(info_t *info)
{
    if (info->argv[1]) {
        int exitcheck = _erratoi(info->argv[1]);
        if (exitcheck == -1) {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return 1;
        }
        info->err_num = exitcheck;
    } else {
        info->err_num = -1;
    }
    return -2;
}

int _mycd(info_t *info)
{
    char buffer[1024];
    char *dir = info->argv[1] ? info->argv[1] : _getenv(info, "HOME=");
    
    if (!dir)
        dir = _getenv(info, "PWD=");
    
    if (!_strcmp(info->argv[1], "-") && !_getenv(info, "OLDPWD=")) {
        _puts(getcwd(buffer, 1024));
        _putchar('\n');
        return 1;
    }

    int chdir_ret = chdir(dir);

    if (chdir_ret == -1) {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]);
        _eputchar('\n');
    } else {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return 0;
}

int _myhelp(info_t *info)
{
    _puts("help call works. Function not yet implemented\n");
    return 0;
}
