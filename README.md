# GHC

**G**rauwoelfchen's dvorak keymaps and settings for **H**elix keyboard **C**ustomization.

```
# Layer 0
,-----------------------------------------.               ,-----------------------------------------.
|      |  '   |  ,   |  .   |  P   |  Y   |               |   F  |   G  |   C  |   R  |   L  |      |
|------+------+------+------+------+------|               |------+------+------+------+------+------|
|      |  A   |  O   |  E   |  U   |  I   |               |   D  |   H  |   T  |   N  |   S  |      |
|------+------+------+------+------+------|               |------+------+------+------+------+------|
|      |  ;   |  Q   |  J   |  K   |  X   |               |   B  |   M  |   W  |   V  |   Z  |      |
|------+------+------+------+------+------+------- -------+------+------+------+------+------+------|
|      | Esc  | Tab  |      | Shft | Bksp | Ctrl | |  Alt | Spce | Lowr |   _  |   /  | Entr |      |
`------------------------------------------------- -------------------------------------------------'

# Lower
,-----------------------------------------.               ,-----------------------------------------.
|      |  !   |  @   |  {   |  }   |  |   |               | Pgup |   7  |   8  |   9  |   *  |      |
|------+------+------+------+------+------|               |------+------+------+------+------+------|
|      |  #   |  $   |  (   |  )   |  `   |               | Pgdn |   4  |   5  |   6  |   +  |      |
|------+------+------+------+------+------|               |------+------+------+------+------+------|
|      |  %   |  ^   |  [   |  ]   |  ~   |               |   &  |   1  |   2  |   3  |   \  |      |
|------+------+------+------+------+------+------- -------+------+------+------+------+------+------|
|      | Rais | Tab  |      |      |      | Ctrl | |  Alt |      | Rset |      |   0  |   =  |      |
`------------------------------------------------- -------------------------------------------------'

# Raise
,-----------------------------------------.               ,-----------------------------------------.
|      |      |      |  ↑   |      |      |               |      |   F7 |   F8 |   F9 |      |      |
|------+------+------+------+------+------|               |------+------+------+------+------+------|
|      |      |  ←   |  ↓   |  →   |      |               |      |   F4 |   F5 |   F6 |      |      |
|------+------+------+------+------+------|               |------+------+------+------+------+------|
|      |      |      |      |      |      |               |      |   F1 |   F2 |   F3 |      |      |
|------+------+------+------+------+------+------- -------+------+------+------+------+------+------|
|      | Rset | Tab  |      |      |      | Ctrl | |  Alt |      | Rset |      |      |      |      |
`------------------------------------------------- -------------------------------------------------'
```

## Build

```zsh
% cd qmk_firmware/keyboards/helix/rev2/keymaps
% git clone git@gitlab.com:grauwoelfchen/ghc.git grauwoelfchen

# replace serial.c
% cd grauwoelfchen
% cp serial.c /path/to/helix/

% cd ../../../../
% make helix:grauwoelfchen
% make helix:grauwoelfchen:avrdude
```

## Note

On Funtoo, use gcc 4.9.2 (from Gentoo's ebuilds in `/usr/portage`)  
as `cross-avr/gcc`.  

See https://www.funtoo.org/Cross-compiling_with_Crossdev

```zsh
% ego query v gcc
...

% ls -l /usr/local/portage-crossdev/cross-avr
total 0
lrwxrwxrwx 1 root root 53 Aug  4 05:57 avr-libc -> /var/git/meta-repo/kits/dev-kit/dev-embedded/avr-libc
lrwxrwxrwx 1 root root 51 Aug  4 05:57 binutils -> /var/git/meta-repo/kits/core-kit/sys-devel/binutils
lrwxrwxrwx 1 root root 32 Aug  4 07:00 gcc -> /usr/local/portage/sys-devel/gcc
lrwxrwxrwx 1 root root 43 Aug  4 05:56 gdb -> /var/git/meta-repo/kits/nokit/sys-devel/gdb

% sudo su
# curl -LO <link> gcc-4.9.2.ebuild
# ebuild gcc-4.9.2.ebuild manifest

% ls -l /usr/local/portage-crossdev/cross-avr/gcc
total 12
lrwxrwxrwx 1 root root   32 Aug  4 07:25 files -> /usr/portage/sys-devel/gcc/files
-rw-r--r-- 1 root root 1520 Aug  4 07:52 gcc-4.9.2.ebuild
-rw-r--r-- 1 root root 1870 Aug  4 07:52 Manifest
```

## License

`GPL-3.0`

See also: [qmk_firmware](https://github.com/jackhumbert/qmk_firmware) project.


```
GHC
Copyright (c) 2018 Yasuhiro Asaka
```

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
