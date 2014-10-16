Name        : ipmtube 
Version     : 3.2.10
Release     : 6.el6
Summary     : The Ipm network monitor data provider
Source0	    : ipmtube-3.2.10.tar.gz
License     : GPL
Group       : Applications/Network
BuildArch   : x86_64
BuildRoot   : %{_tmppath}/%{name}-buildroot

%description
Analysis application layer protocol base on netflow. Write 
protocol field and network performance data to database.

%prep

%setup -q

%build

%install
install -m 0755 -d 				$RPM_BUILD_ROOT/usr/local/bin
install -m 0755 ipmtube				$RPM_BUILD_ROOT/usr/local/bin/ipmtube
install -m 0755 -d 				$RPM_BUILD_ROOT/etc
install -m 0755 ipm-proto			$RPM_BUILD_ROOT/etc/ipm-proto
install -m 0755 -d 				$RPM_BUILD_ROOT/usr/local/lib
install -m 0755 libipmtube-3.2.10.so 		$RPM_BUILD_ROOT/usr/local/lib/libipmtube-3.2.10.so
install -m 0755 -d 				$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins
install -m 0755 libbgpPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libbgpPlugin-3.2.10.so
install -m 0755 libdbPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libdbPlugin-3.2.10.so
install -m 0755 libdnsPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libdnsPlugin-3.2.10.so
install -m 0755 libimapPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libimapPlugin-3.2.10.so
install -m 0755 liboraclePlugin-3.2.10.so	$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/liboraclePlugin-3.2.10.so
install -m 0755 libsmtpPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libsmtpPlugin-3.2.10.so
install -m 0755 libdb2Plugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libdb2Plugin-3.2.10.so
install -m 0755 libhttpPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libhttpPlugin-3.2.10.so
install -m 0755 libmysqlPlugin-3.2.10.so	$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libmysqlPlugin-3.2.10.so
install -m 0755 libmqPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libmqPlugin-3.2.10.so
install -m 0755 libpopPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libpopPlugin-3.2.10.so
install -m 0755 libsqlserverPlugin-3.2.10.so	$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libsqlserverPlugin-3.2.10.so
install -m 0755 libsipPlugin-3.2.10.so		$RPM_BUILD_ROOT/usr/local/lib/ipmtube/plugins/libsipPlugin-3.2.10.so

%clean
rm -rf $RPM_BUILD_ROOT

%post
cd /usr/local/lib
ln -s -f  libipmtube-3.2.10.so		libipmtube.so
cd /usr/local/lib/ipmtube/plugins
ln -s -f  libbgpPlugin-3.2.10.so  	libbgpPlugin.so
ln -s -f  libdbPlugin-3.2.10.so  	libdbPlugin.so
ln -s -f  libdnsPlugin-3.2.10.so  	libdnsPlugin.so
ln -s -f  libimapPlugin-3.2.10.so  	libimapPlugin.so
ln -s -f  liboraclePlugin-3.2.10.so  	liboraclePlugin.so
ln -s -f  libsmtpPlugin-3.2.10.so  	libsmtpPlugin.so
ln -s -f  libdb2Plugin-3.2.10.so  	libdb2Plugin.so
ln -s -f  libhttpPlugin-3.2.10.so  	libhttpPlugin.so
ln -s -f  libmysqlPlugin-3.2.10.so  	libmysqlPlugin.so
ln -s -f  libmqPlugin-3.2.10.so  	libmqPlugin.so
ln -s -f  libpopPlugin-3.2.10.so  	libpopPlugin.so
ln -s -f  libsqlserverPlugin-3.2.10.so  libsqlserverPlugin.so
ln -s -f  libsipPlugin-3.2.10.so  	libsipPlugin.so

%files

%dir /usr/local/bin
/usr/local/bin/ipmtube

%dir /etc
/etc/ipm-proto

%dir /usr/local/lib
/usr/local/lib/libipmtube-3.2.10.so

%dir /usr/local/lib/ipmtube/plugins
/usr/local/lib/ipmtube/plugins/libbgpPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libdbPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libdnsPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libimapPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/liboraclePlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libsmtpPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libdb2Plugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libhttpPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libmysqlPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libmqPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libpopPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libsqlserverPlugin-3.2.10.so
/usr/local/lib/ipmtube/plugins/libsipPlugin-3.2.10.so
