# bitrig_ksh_linux

bash sucks, we know, so use this port to run Bitrig's ksh on linux.  Enjoy a
proper shell instead of having to use bash, LIKE AN ANIMAL!

The following steps were done on Fedora & Ubuntu.

## install the following packages on linux

Fedora:
```
bmake
libbsd-devel
```

Ubuntu:
```
bmake
libbsd-dev
```

## compile and install
```
git clone https://github.com/marcopeereboom/bitrig_ksh_linux.git
cd bitrig_ksh_linux
bmake
sudo bmake install
sudo sh -c 'echo /bin/ksh >> /etc/shells'
```

## switch user shell
```
sudo usermod -s /bin/ksh $USER
```
