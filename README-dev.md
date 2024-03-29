# codeblocks_IDE_msys2

##Build Time Requirements
# Run from MSys2 *Mingw prompt*
```
pacman -S --noconfirm --needed zip;
pacman -S --noconfirm --needed rsync;
pacman -S --noconfirm --needed subversion;
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
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-wxwidgets3.2-msw;
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-wxwidgets3.2-msw-cb_headers;
```

## Needs done only once to clone/checkout git and SVN repos
# Run from MSys2 *Mingw prompt*
```
mkdir -p ~/devel && cd ~/devel && \
git clone https://github.com/stahta01/codeblocks_IDE_msys2.git codeblocks-dev && \
( cd codeblocks-dev && git checkout cb_source ) && \
svn checkout --ignore-externals svn://svn.code.sf.net/p/codeblocks/code/trunk codeblocks-dev && \
cd ~/devel/codeblocks-dev && svn update --ignore-externals . ;
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
git checkout master && \
git pull && \
git checkout cb_source && git rebase master
```

# update from SVN
# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev && \
git checkout cb_source && git restore . && git pull && \
svn cleanup && svn revert -R . && \
svn update --ignore-externals . && \
svn status -q && \
rm -fr src/templates/ && \
mkdir -p src/templates/ && \
git restore .gitignore && \
git restore src/plugins/contrib/SpellChecker/update && \
rm .git/index && git reset && git status -uno;
```

# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev && git restore . && \
git checkout cb_common && git rebase cb_source
```

# Build CB Projects

## Build Code::Blocks MSys2 project
# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev/src
./update 32_msys2
```

# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev/src/output32_msys2
./codeblocks.exe -p msys2_mgw
```
