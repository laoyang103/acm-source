Name        : dsas 
Version     : 1.0.0
Release     : 1.el6
Summary     : Dump and extract packets
Source0	    : dsas-1.0.0.tar.gz
License     : GPL
Group       : Applications/Packet
BuildArch   : x86_64
BuildRoot   : %{_tmppath}/%{name}-buildroot

%description
Dsas can dump and extract a large number of packets fast.

%prep

%setup -q

%build

%install
install -m 0755 -d 			$RPM_BUILD_ROOT/lib/modules/2.6.32-431.el6.x86_64/kernel/net/i_cap
install -m 0755 i_cap.ko		$RPM_BUILD_ROOT/lib/modules/2.6.32-431.el6.x86_64/kernel/net/i_cap/i_cap.ko
install -m 0755 -d 			$RPM_BUILD_ROOT/usr/local/bin
install -m 0755 dsas			$RPM_BUILD_ROOT/usr/local/bin/dsas
install -m 0755 dsas_extract		$RPM_BUILD_ROOT/usr/local/bin/dsas_extract
install -m 0755 -d 			$RPM_BUILD_ROOT/usr/local/lib
install -m 0755 libicap.so		$RPM_BUILD_ROOT/usr/local/lib/libicap.so

%clean
rm -rf $RPM_BUILD_ROOT

%post
ln -s -f  /usr/local/lib/libicap.so	/usr/lib/libicap.so
/sbin/depmod 2.6.32-431.el6.x86_64
modprobe i_cap

%files

%dir /usr/local/bin
/usr/local/bin/dsas
/usr/local/bin/dsas_extract

%dir /usr/local/lib
/usr/local/lib/libicap.so

%dir /lib/modules/2.6.32-431.el6.x86_64/kernel/net/i_cap
/lib/modules/2.6.32-431.el6.x86_64/kernel/net/i_cap/i_cap.ko
