# bitrig_ksh_linux

bash sucks, we know so use this gem to run Bitrig's ksh on linux.

The following steps were done on Fedora.

## install the following packages on linux
```
bmake
libbsd-devel
```

## compile and install
```
cd bitrig_ksh_linux
bmake
sudo bmake install
sudo sh -c 'echo /bin/ksh >> /etc/shells'
```

## switch user shell
```
sudo usermod -s /bin/ksh $USER
```

That's it!  Enjoy a proper shell instead of having to use bash, LIKE AN ANIMAL!
