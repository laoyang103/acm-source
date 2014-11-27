Name        : ipms 
Version     : 5.0.1
Release     : 6.el6
Summary     : Receive Netflow from ipmtube and write it to rrd database.
Source0	    : ipms-5.0.1.tar.gz
License     : GPL
Group       : Applications/Network
BuildArch   : x86_64
BuildRoot   : %{_tmppath}/%{name}-buildroot

%description
Receive Netflow from ipmtube and write it to rrd database.

%prep

%setup -q

%build

%install
install -m 0755 -d 			$RPM_BUILD_ROOT/usr/local/bin
install -m 0755 ipms			$RPM_BUILD_ROOT/usr/local/bin/ipms
install -m 0755 -d 			$RPM_BUILD_ROOT/usr/local/lib
install -m 0755 libipms-5.0.1.so 	$RPM_BUILD_ROOT/usr/local/lib/libipms-5.0.1.so
install -m 0755 libipmsreport-5.0.1.so 	$RPM_BUILD_ROOT/usr/local/lib/libipmsreport-5.0.1.so
install -m 0755 -d 			$RPM_BUILD_ROOT/usr/local/lib/ipms/plugins
install -m 0755 netflowPlugin.so 	$RPM_BUILD_ROOT/usr/local/lib/ipms/plugins/netflowPlugin.so
install -m 0755 rrdPlugin.so 		$RPM_BUILD_ROOT/usr/local/lib/ipms/plugins/rrdPlugin.so    
install -m 0755 sflowPlugin.so 		$RPM_BUILD_ROOT/usr/local/lib/ipms/plugins/sflowPlugin.so  

%clean
rm -rf $RPM_BUILD_ROOT

%post
cd /usr/local/lib
ln -s -f  libipms-5.0.1.so		libipms.so
ln -s -f  libipmsreport-5.0.1.so	libipmsreport.so

%files

%dir /usr/local/bin
/usr/local/bin/ipms

%dir /usr/local/lib
/usr/local/lib/libipms-5.0.1.so
/usr/local/lib/libipmsreport-5.0.1.so

%dir /usr/local/lib/ipms/plugins
/usr/local/lib/ipms/plugins/netflowPlugin.so
/usr/local/lib/ipms/plugins/rrdPlugin.so    
/usr/local/lib/ipms/plugins/sflowPlugin.so  
