# codeblocks_IDE_msys2

##Build Time Requirements
# Run from MSys2 *Mingw prompt*
```
pacman -S --noconfirm --needed rsync;
pacman -S --noconfirm --needed subversion;
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-7zip;
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-gcc;
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-cppcheck;
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-boost;
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-hunspell-en;
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-hunspell;
```

##Run Time Requirements
# Run from MSys2 *Mingw prompt*
```
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-drmingw;
```

## Needs done only once to clone/checkout git and SVN repos
# Run from MSys2 *Mingw prompt*
```
mkdir -p ~/devel && cd ~/devel && \
git clone https://github.com/stahta01/codeblocks_IDE_msys2.git codeblocks-dev && \
cd codeblocks-dev && git checkout wx_mono_build && \
svn checkout --ignore-externals svn://svn.code.sf.net/p/codeblocks/code/trunk codeblocks-svn && \
cd ~/devel/codeblocks-dev/codeblocks-svn && svn cleanup && svn revert -R . && \
svn update --ignore-externals . ;
```

# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev && \
git config core.autocrlf input && \
git config core.eol lf && \
git config --bool pull.rebase true
```

# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev && \
git checkout wx_mono_build && git restore . && git pull && \
cd ~/devel/codeblocks-dev/codeblocks-svn && \
svn cleanup && svn revert -R . && \
svn update --ignore-externals . && \
svn status -q
```

# Build CB Projects using CB IDE
## Build Code::Blocks MSys2 core project
## Build Code::Blocks MSys2 contrib workspace

# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev/codeblocks-svn/src
#./update 32_msys2
```

# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev/codeblocks-svn/src/output32_msys2
#./codeblocks.exe -p msys2_wx_mono_build
```
