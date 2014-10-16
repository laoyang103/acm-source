Name        : rrdtool
Version     : 4.2.0
Release     : 6.el6
Summary     : Round Robin Database Tool to store and display time-series data
Source0	    : rrdtool-4.2.0.tar.gz
License     : GPL
Group       : Applications/Databases
BuildArch   : x86_64
BuildRoot   : %{_tmppath}/%{name}-buildroot

%description
RRD is the Acronym for Round Robin Database. RRD is a system to store and
display time-series data (i.e. network bandwidth, machine-room temperature,
server load average). It stores the data in a very compact way that will not
expand over time, and it presents useful graphs by processing the data to
enforce a certain data density. It can be used either via simple wrapper
scripts (from shell or Perl) or via frontends that poll network devices and
put a friendly user interface on it.

%prep

%setup -q

%build

%install
install -m 0755 -d 			$RPM_BUILD_ROOT/usr/bin
install -m 0755 rrdtool 		$RPM_BUILD_ROOT/usr/bin/rrdtool  
install -m 0755 rrdcached 		$RPM_BUILD_ROOT/usr/bin/rrdcached
install -m 0755 rrdcgi 			$RPM_BUILD_ROOT/usr/bin/rrdcgi 	 
install -m 0755 rrdupdate 		$RPM_BUILD_ROOT/usr/bin/rrdupdate
install -m 0755 -d 			$RPM_BUILD_ROOT/usr/lib64
install -m 0755 librrd.so.4.2.0 	$RPM_BUILD_ROOT/usr/lib64/librrd.so.4.2.0   
install -m 0755 librrd_th.so.4.2.0 	$RPM_BUILD_ROOT/usr/lib64/librrd_th.so.4.2.0

%clean
rm -rf $RPM_BUILD_ROOT

%post
cd /usr/lib64
ln -s -f  librrd.so.4.2.0  	librrd.so.4
ln -s -f  librrd.so.4.2.0  	librrd.so
ln -s -f  librrd_th.so.4.2.0  	librrd_th.so.4
ln -s -f  librrd_th.so.4.2.0  	librrd_th.so

%files

%dir /usr/bin
/usr/bin/rrdtool  
/usr/bin/rrdcached
/usr/bin/rrdcgi 	 
/usr/bin/rrdupdate

%dir /usr/lib64
/usr/lib64/librrd.so.4.2.0   
/usr/lib64/librrd_th.so.4.2.0
