Name        : apache-tomcat
Version     : 6.0.37
Release     : 6.el6
Summary     : Apache tomcat for ipm system
Source0	    : apache-tomcat-6.0.37.tar.gz
License     : GPL
Group       : Applications/Web
BuildArch   : x86_64
BuildRoot   : %{_tmppath}/%{name}-buildroot

%description
Apache tomcat for ipm system

%prep

%setup -q

%build

%install
install -m 0755 -d			$RPM_BUILD_ROOT/opt
install -m 0755 -d			$RPM_BUILD_ROOT/opt/apache-tomcat-6.0.37
install -m 0755 ipm.sql			$RPM_BUILD_ROOT/opt/apache-tomcat-6.0.37/ipm.sql
install -m 0755 tomcat.tar.gz		$RPM_BUILD_ROOT/opt/apache-tomcat-6.0.37/tomcat.tar.gz
install -m 0755 -d			$RPM_BUILD_ROOT/usr/local/var
install -m 0755 monitor.sh		$RPM_BUILD_ROOT/usr/local/var/monitor.sh
install -m 0755 monitor.cron		$RPM_BUILD_ROOT/usr/local/var/monitor.cron
install -m 0755 my.cnf			$RPM_BUILD_ROOT/usr/local/var/my.cnf
install -m 0755 rc.local		$RPM_BUILD_ROOT/usr/local/var/rc.local

%clean
rm -rf $RPM_BUILD_ROOT

%post
cd /opt/apache-tomcat-6.0.37
tar -zxvf tomcat.tar.gz -C /opt/apache-tomcat-6.0.37

chkconfig iptables off
chkconfig mysqld on

\cp /usr/local/var/my.cnf /etc
service mysqld start
service iptables stop

mysqladmin -uroot password '123456'
mysql -uroot -p123456 < ipm.sql

\cp /usr/local/var/rc.local /etc
ln -s -f  /usr/bin/twopi /usr/local/bin/twopi
crontab /usr/local/var/monitor.cron

%files

%dir /opt
%dir /opt/apache-tomcat-6.0.37
/opt/apache-tomcat-6.0.37/ipm.sql
/opt/apache-tomcat-6.0.37/tomcat.tar.gz

%dir /usr/local/var
/usr/local/var/monitor.sh
/usr/local/var/monitor.cron
/usr/local/var/my.cnf
/usr/local/var/rc.local
