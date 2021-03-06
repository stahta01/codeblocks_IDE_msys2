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
```

##Run Time Requirements
# Run from MSys2 *Mingw prompt*
```
pacman -S --noconfirm --needed ${MINGW_PACKAGE_PREFIX}-drmingw;
pacman -U ~/devel/MINGW-packages/mingw-w64-wxWidgets3.1/${MINGW_PACKAGE_PREFIX}-wxmsw3.1-*-any.pkg.tar.zst;
```

```
mkdir -p ~/devel && cd ~/devel && \
git clone https://github.com/stahta01/codeblocks_IDE_msys2.git codeblocks-dev && \
( cd codeblocks-dev && git checkout cb_source ) && \
svn checkout --ignore-externals svn://svn.code.sf.net/p/codeblocks/code/trunk codeblocks-dev && \
cd ~/devel/codeblocks-dev && svn update --ignore-externals . ;
```

###Record Results
```
cd ~/devel/codeblocks-dev && \
git checkout cb_source && git restore . && git pull && \
svn cleanup && svn revert -R . && \
svn update --ignore-externals . && \
rm -fr src/templates/ && \
mkdir -p src/templates/ && \
svn status -q && git status -uno;
```
####Results
```
$ git status -uno
...
        modified:   .gitignore
        modified:   src/plugins/contrib/SpellChecker/update
```

```
git status -uno;  # Commit needed changes

git restore .     # Revert changes that are not needed
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
./update 31_msys2
```

# Run from MSys2 *Mingw prompt*
```
cd ~/devel/codeblocks-dev/src/output31_msys2
./codeblocks.exe -p msys2_mgw
```
