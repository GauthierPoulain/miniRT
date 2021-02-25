#!/bin/bash

_END=$'\e[1;0m'
_BOLD=$'\e[1;1m'
_UNDER=$'\e[1;4m'
_REV=$'\e[1;7m'

_RED=$'\e[1;31m'
_GREEN=$'\e[1;32m'
_YELLOW=$'\e[1;33m'
_BLUE=$'\e[1;34m'
_PURPLE=$'\e[1;35m'
_CYAN=$'\e[1;36m'
_WHITE=$'\e[1;37m'

_IGREY=$'\e[1;40m'
_IRED=$'\e[1;41m'
_IGREEN=$'\e[1;42m'
_IYELLOW=$'\e[1;43m'
_IBLUE=$'\e[1;44m'
_IPURPLE=$'\e[1;45m'
_ICYAN=$'\e[1;46m'
_IWHITE=$'\e[1;47m'

printf "${_BLUE}${_BOLD}miniRT tester${_END}\n"

# printf "remaking project ...\n"
# make re > /dev/null
# printf "\n"

printf "missing args :\n"
./miniRT
printf "\n"

printf "check error output :\n"
printf "only stdout = \n"
./miniRT 2> /dev/null
printf "only stderr = \n"
./miniRT 1> /dev/null
printf "\n"

printf "check exit code :\n"
printf "success = "
./miniRT ./scenes/for_tester.rt --save &> /dev/null
echo $?
printf "error = "
./miniRT &> /dev/null
echo $?
printf "\n"

printf "wrong second argument :\n"
./miniRT ./scenes/for_tester.rt ui
printf "\n"

printf "invalid path :\n"
./miniRT ./hello.rt
printf "\n"

printf "wrong file extension :\n"
./miniRT ./scenes/errors/invalid_ext.ui
printf "\n"

printf "directory :\n"
./miniRT ./scenes/errors/directory.rt
printf "\n"

printf "empty file :\n"
./miniRT ./scenes/errors/empty.rt
printf "\n"

printf "no resolution :\n"
./miniRT ./scenes/errors/no_resolution.rt
printf "\n"

printf "no camera :\n"
./miniRT ./scenes/errors/no_camera.rt
printf "\n"

printf "invalid rgb format :\n"
./miniRT ./scenes/errors/invalid_rgb.rt
printf "\n"

printf "invalid direction :\n"
./miniRT ./scenes/errors/invalid_direction.rt
printf "\n"

