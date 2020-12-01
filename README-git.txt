Git Branch Information

$ git branch --list
  cb_headers
  cb_pch
* cb_source
  cleanup
  master
  staging
  start
  testing

master            base branch that other branches tend to be base on
staging           branch that is used to move changes to master branch
testing           branch that is used to test changes before moving them to staging
cb_source         branch to do changes to main CB source code

start             utility branch to used to rebase changes to master and staging branches
cleanup           utility branch to help remove files from folder

cb_headers        experimental branch to reduce headers included inside CB SDK headers
cb_pch            experimental branch to do Precompiled Headers related changes
cb_deprecate      experimental branch to fix wxWidgets 1.0 deprecate warnings that I have enable in my wxWidgets branch
