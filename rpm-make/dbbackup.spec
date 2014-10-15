Name: dbbackup
Version: 1
Release: 0
Summary: Database backup rpm
Source0: dbbackup-1.0.tar.gz
License: GPL
Group: Rahul
BuildArch: noarch
BuildRoot: %{_tmppath}/%{name}-buildroot
%description
Write some descripton about your package.
%prep
%setup -q
%build
%install
install -m 0755 -d $RPM_BUILD_ROOT/etc/dbbackup
install -m 0755 backup.sh $RPM_BUILD_ROOT/etc/dbbackup/backup.sh
%clean
rm -rf $RPM_BUILD_ROOT
%post
echo . .
echo .Wring some descripton here to show after package installation!.
%files
%dir /etc/dbbackup
/etc/dbbackup/backup.sh
