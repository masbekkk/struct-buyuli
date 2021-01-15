#
# DO NOT EDIT THIS FILE
#
# It is automatically generated by grub-mkconfig using templates
# from /etc/grub.d and settings from /etc/default/grub
#

### BEGIN /etc/grub.d/00_header ###
if [ -s $prefix/grubenv ]; then
  set have_grubenv=true
  load_env
fi
if [ "${initrdfail}" = 2 ]; then
   set initrdfail=
elif [ "${initrdfail}" = 1 ]; then
   set next_entry="${prev_entry}"
   set prev_entry=
   save_env prev_entry
   if [ "${next_entry}" ]; then
      set initrdfail=2
   fi
fi
if [ "${next_entry}" ] ; then
   set default="${next_entry}"
   set next_entry=
   save_env next_entry
   set boot_once=true
else
   set default="0"
fi

if [ x"${feature_menuentry_id}" = xy ]; then
  menuentry_id_option="--id"
else
  menuentry_id_option=""
fi

export menuentry_id_option

if [ "${prev_saved_entry}" ]; then
  set saved_entry="${prev_saved_entry}"
  save_env saved_entry
  set prev_saved_entry=
  save_env prev_saved_entry
  set boot_once=true
fi

function savedefault {
  if [ -z "${boot_once}" ]; then
    saved_entry="${chosen}"
    save_env saved_entry
  fi
}
function initrdfail {
    if [ -n "${have_grubenv}" ]; then if [ -n "${partuuid}" ]; then
      if [ -z "${initrdfail}" ]; then
        set initrdfail=1
        if [ -n "${boot_once}" ]; then
          set prev_entry="${default}"
          save_env prev_entry
        fi
      fi
      save_env initrdfail
    fi; fi
}
function recordfail {
  set recordfail=1
  if [ -n "${have_grubenv}" ]; then if [ -z "${boot_once}" ]; then save_env recordfail; fi; fi
}
function load_video {
  if [ x$feature_all_video_module = xy ]; then
    insmod all_video
  else
    insmod efi_gop
    insmod efi_uga
    insmod ieee1275_fb
    insmod vbe
    insmod vga
    insmod video_bochs
    insmod video_cirrus
  fi
}

if [ x$feature_default_font_path = xy ] ; then
   font=unicode
else
insmod part_msdos
insmod ext2
set root='hd0,msdos5'
if [ x$feature_platform_search_hint = xy ]; then
  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
else
  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
fi
    font="/usr/share/grub/unicode.pf2"
fi

if loadfont $font ; then
  set gfxmode=auto
  load_video
  insmod gfxterm
  set locale_dir=$prefix/locale
  set lang=en_GB
  insmod gettext
fi
terminal_output gfxterm
if [ "${recordfail}" = 1 ] ; then
  set timeout=30
else
  if [ x$feature_timeout_style = xy ] ; then
    set timeout_style=hidden
    set timeout=0
  # Fallback hidden-timeout code in case the timeout_style feature is
  # unavailable.
  elif sleep --interruptible 0 ; then
    set timeout=0
  fi
fi
### END /etc/grub.d/00_header ###

### BEGIN /etc/grub.d/05_debian_theme ###
set menu_color_normal=white/black
set menu_color_highlight=black/light-gray
### END /etc/grub.d/05_debian_theme ###

### BEGIN /etc/grub.d/10_linux_proxy ###

function gfxmode {
	set gfxpayload="${1}"
	if [ "${1}" = "keep" ]; then
		set vt_handoff=vt.handoff=7
	else
		set vt_handoff=
	fi
}
if [ "${recordfail}" != 1 ]; then
  if [ -e ${prefix}/gfxblacklist.txt ]; then
    if hwmatch ${prefix}/gfxblacklist.txt 3; then
      if [ ${match} = 0 ]; then
        set linux_gfx_mode=keep
      else
        set linux_gfx_mode=text
      fi
    else
      set linux_gfx_mode=text
    fi
  else
    set linux_gfx_mode=keep
  fi
else
  set linux_gfx_mode=text
fi
export linux_gfx_mode



### END /etc/grub.d/10_linux_proxy ###

### BEGIN /etc/grub.d/40_custom_proxy ###
menuentry "Ubuntu" --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-simple-893cb6a1-b7fb-40e6-a6b2-60027d573d84' {
	recordfail
	load_video
	gfxmode $linux_gfx_mode
	insmod gzio
	if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
	insmod part_msdos
	insmod ext2
	set root='hd0,msdos5'
	if [ x$feature_platform_search_hint = xy ]; then
	  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
	else
	  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
	fi
	linux	/boot/vmlinuz-5.4.0-53-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro  quiet splash $vt_handoff
	initrd	/boot/initrd.img-5.4.0-53-generic
}
### END /etc/grub.d/40_custom_proxy ###

### BEGIN /etc/grub.d/41_linux_proxy ###
submenu "Advanced options for Ubuntu"{
menuentry "Ubuntu, with Linux 5.4.0-53-generic" --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-5.4.0-53-generic-advanced-893cb6a1-b7fb-40e6-a6b2-60027d573d84' {
		recordfail
		load_video
		gfxmode $linux_gfx_mode
		insmod gzio
		if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
		insmod part_msdos
		insmod ext2
		set root='hd0,msdos5'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
		else
		  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
		fi
		echo	'Loading Linux 5.4.0-53-generic ...'
		linux	/boot/vmlinuz-5.4.0-53-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro  quiet splash $vt_handoff
		echo	'Loading initial ramdisk ...'
		initrd	/boot/initrd.img-5.4.0-53-generic
}
menuentry "Ubuntu, with Linux 5.4.0-53-generic (recovery mode)" --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-5.4.0-53-generic-recovery-893cb6a1-b7fb-40e6-a6b2-60027d573d84' {
		recordfail
		load_video
		insmod gzio
		if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
		insmod part_msdos
		insmod ext2
		set root='hd0,msdos5'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
		else
		  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
		fi
		echo	'Loading Linux 5.4.0-53-generic ...'
		linux	/boot/vmlinuz-5.4.0-53-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr 
		echo	'Loading initial ramdisk ...'
		initrd	/boot/initrd.img-5.4.0-53-generic
}
menuentry "Ubuntu, with Linux 5.4.0-52-generic" --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-5.4.0-52-generic-advanced-893cb6a1-b7fb-40e6-a6b2-60027d573d84' {
		recordfail
		load_video
		gfxmode $linux_gfx_mode
		insmod gzio
		if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
		insmod part_msdos
		insmod ext2
		set root='hd0,msdos5'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
		else
		  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
		fi
		echo	'Loading Linux 5.4.0-52-generic ...'
		linux	/boot/vmlinuz-5.4.0-52-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro  quiet splash $vt_handoff
		echo	'Loading initial ramdisk ...'
		initrd	/boot/initrd.img-5.4.0-52-generic
}
menuentry "Ubuntu, with Linux 5.4.0-52-generic (recovery mode)" --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-5.4.0-52-generic-recovery-893cb6a1-b7fb-40e6-a6b2-60027d573d84' {
		recordfail
		load_video
		insmod gzio
		if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
		insmod part_msdos
		insmod ext2
		set root='hd0,msdos5'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
		else
		  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
		fi
		echo	'Loading Linux 5.4.0-52-generic ...'
		linux	/boot/vmlinuz-5.4.0-52-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr 
		echo	'Loading initial ramdisk ...'
		initrd	/boot/initrd.img-5.4.0-52-generic
}
menuentry "Ubuntu, with Linux 5.4.0-26-generic" --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-5.4.0-26-generic-advanced-893cb6a1-b7fb-40e6-a6b2-60027d573d84' {
		recordfail
		load_video
		gfxmode $linux_gfx_mode
		insmod gzio
		if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
		insmod part_msdos
		insmod ext2
		set root='hd0,msdos5'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
		else
		  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
		fi
		echo	'Loading Linux 5.4.0-26-generic ...'
		linux	/boot/vmlinuz-5.4.0-26-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro  quiet splash $vt_handoff
		echo	'Loading initial ramdisk ...'
		initrd	/boot/initrd.img-5.4.0-26-generic
}
menuentry "Ubuntu, with Linux 5.4.0-26-generic (recovery mode)" --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-5.4.0-26-generic-recovery-893cb6a1-b7fb-40e6-a6b2-60027d573d84' {
		recordfail
		load_video
		insmod gzio
		if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
		insmod part_msdos
		insmod ext2
		set root='hd0,msdos5'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
		else
		  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
		fi
		echo	'Loading Linux 5.4.0-26-generic ...'
		linux	/boot/vmlinuz-5.4.0-26-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr 
		echo	'Loading initial ramdisk ...'
		initrd	/boot/initrd.img-5.4.0-26-generic
}
}
### END /etc/grub.d/41_linux_proxy ###

### BEGIN /etc/grub.d/42_linux_zfs ###
### END /etc/grub.d/42_linux_zfs ###

### BEGIN /etc/grub.d/43_linux_xen ###

### END /etc/grub.d/43_linux_xen ###

### BEGIN /etc/grub.d/44_os-prober ###
menuentry 'Linux Mint 20 Ulyana (20) (on /dev/sda5)' --class linuxmint --class gnu-linux --class gnu --class os $menuentry_id_option 'osprober-gnulinux-simple-DCC6-3013' {
	insmod part_msdos
	insmod exfat
	set root='hd0,msdos5'
	if [ x$feature_platform_search_hint = xy ]; then
	  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos7 --hint-efi=hd0,msdos7 --hint-baremetal=ahci0,msdos7  DCC6-3013
	else
	  search --no-floppy --fs-uuid --set=root DCC6-3013
	fi
	linux /boot/vmlinuz-5.4.0-53-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro quiet splash
	initrd /boot/initrd.img-5.4.0-53-generic
}
submenu 'Advanced options for Linux Mint 20 Ulyana (20) (on /dev/sda7)' $menuentry_id_option 'osprober-gnulinux-advanced-DCC6-3013' {
	menuentry 'Linux Mint 20 Cinnamon (on /dev/sda7)' --class gnu-linux --class gnu --class os $menuentry_id_option 'osprober-gnulinux-/boot/vmlinuz-5.4.0-53-generic--DCC6-3013' {
		insmod part_msdos
		insmod exfat
		set root='hd0,msdos7'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos7 --hint-efi=hd0,msdos7 --hint-baremetal=ahci0,msdos7  DCC6-3013
		else
		  search --no-floppy --fs-uuid --set=root DCC6-3013
		fi
		linux /boot/vmlinuz-5.4.0-53-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro quiet splash
		initrd /boot/initrd.img-5.4.0-53-generic
	}
	menuentry 'Linux Mint 20 Cinnamon, with Linux 5.4.0-53-generic (on /dev/sda7)' --class gnu-linux --class gnu --class os $menuentry_id_option 'osprober-gnulinux-/boot/vmlinuz-5.4.0-53-generic--DCC6-3013' {
		insmod part_msdos
		insmod exfat
		set root='hd0,msdos7'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos7 --hint-efi=hd0,msdos7 --hint-baremetal=ahci0,msdos7  DCC6-3013
		else
		  search --no-floppy --fs-uuid --set=root DCC6-3013
		fi
		linux /boot/vmlinuz-5.4.0-53-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro quiet splash
		initrd /boot/initrd.img-5.4.0-53-generic
	}
	menuentry 'Linux Mint 20 Cinnamon, with Linux 5.4.0-53-generic (recovery mode) (on /dev/sda7)' --class gnu-linux --class gnu --class os $menuentry_id_option 'osprober-gnulinux-/boot/vmlinuz-5.4.0-53-generic-root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr-DCC6-3013' {
		insmod part_msdos
		insmod exfat
		set root='hd0,msdos7'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos7 --hint-efi=hd0,msdos7 --hint-baremetal=ahci0,msdos7  DCC6-3013
		else
		  search --no-floppy --fs-uuid --set=root DCC6-3013
		fi
		linux /boot/vmlinuz-5.4.0-53-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr
		initrd /boot/initrd.img-5.4.0-53-generic
	}
	menuentry 'Linux Mint 20 Cinnamon, with Linux 5.4.0-52-generic (on /dev/sda7)' --class gnu-linux --class gnu --class os $menuentry_id_option 'osprober-gnulinux-/boot/vmlinuz-5.4.0-52-generic--DCC6-3013' {
		insmod part_msdos
		insmod exfat
		set root='hd0,msdos7'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos7 --hint-efi=hd0,msdos7 --hint-baremetal=ahci0,msdos7  DCC6-3013
		else
		  search --no-floppy --fs-uuid --set=root DCC6-3013
		fi
		linux /boot/vmlinuz-5.4.0-52-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro quiet splash
		initrd /boot/initrd.img-5.4.0-52-generic
	}
	menuentry 'Linux Mint 20 Cinnamon, with Linux 5.4.0-52-generic (recovery mode) (on /dev/sda7)' --class gnu-linux --class gnu --class os $menuentry_id_option 'osprober-gnulinux-/boot/vmlinuz-5.4.0-52-generic-root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr-DCC6-3013' {
		insmod part_msdos
		insmod exfat
		set root='hd0,msdos7'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos7 --hint-efi=hd0,msdos7 --hint-baremetal=ahci0,msdos7  DCC6-3013
		else
		  search --no-floppy --fs-uuid --set=root DCC6-3013
		fi
		linux /boot/vmlinuz-5.4.0-52-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr
		initrd /boot/initrd.img-5.4.0-52-generic
	}
	menuentry 'Linux Mint 20 Cinnamon, with Linux 5.4.0-26-generic (on /dev/sda7)' --class gnu-linux --class gnu --class os $menuentry_id_option 'osprober-gnulinux-/boot/vmlinuz-5.4.0-26-generic--DCC6-3013' {
		insmod part_msdos
		insmod exfat
		set root='hd0,msdos7'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos7 --hint-efi=hd0,msdos7 --hint-baremetal=ahci0,msdos7  DCC6-3013
		else
		  search --no-floppy --fs-uuid --set=root DCC6-3013
		fi
		linux /boot/vmlinuz-5.4.0-26-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro quiet splash
		initrd /boot/initrd.img-5.4.0-26-generic
	}
	menuentry 'Linux Mint 20 Cinnamon, with Linux 5.4.0-26-generic (recovery mode) (on /dev/sda7)' --class gnu-linux --class gnu --class os $menuentry_id_option 'osprober-gnulinux-/boot/vmlinuz-5.4.0-26-generic-root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr-DCC6-3013' {
		insmod part_msdos
		insmod exfat
		set root='hd0,msdos7'
		if [ x$feature_platform_search_hint = xy ]; then
		  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos7 --hint-efi=hd0,msdos7 --hint-baremetal=ahci0,msdos7  DCC6-3013
		else
		  search --no-floppy --fs-uuid --set=root DCC6-3013
		fi
		linux /boot/vmlinuz-5.4.0-26-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro recovery nomodeset dis_ucode_ldr
		initrd /boot/initrd.img-5.4.0-26-generic
	}
}

set timeout_style=menu
if [ "${timeout}" = 0 ]; then
  set timeout=10
fi
### END /etc/grub.d/44_os-prober ###

### BEGIN /etc/grub.d/45_uefi-firmware ###
### END /etc/grub.d/45_uefi-firmware ###

### BEGIN /etc/grub.d/46_custom_proxy ###

# This file provides an easy way to add custom menu entries.  Simply type the
# menu entries you want to add after this comment.  Be careful not to change
# the 'exec tail' line above.


menuentry "RemixOS"{
	insmod part_gpt
	search --file --no floppy --set=root /RemixOS/system.sfs
	linux /RemixOS/kernel root=/dev/ram0 androidboot.hardware=remix_x86-64
	androidboot.setlinux=permissive CMDLINE REMOUNT_RW=1
	initrd /RemixOS/initrd.img
}
### END /etc/grub.d/46_custom_proxy ###

### BEGIN /etc/grub.d/47_custom ###
if [ -f  ${config_directory}/custom.cfg ]; then
  source ${config_directory}/custom.cfg
elif [ -z "${config_directory}" -a -f  $prefix/custom.cfg ]; then
  source $prefix/custom.cfg;
fi
### END /etc/grub.d/47_custom ###

### BEGIN /etc/grub.d/48_linux_proxy ###
menuentry "Ubuntu" --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-simple-893cb6a1-b7fb-40e6-a6b2-60027d573d84' {
	recordfail
	load_video
	gfxmode $linux_gfx_mode
	insmod gzio
	if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
	insmod part_msdos
	insmod ext2
	set root='hd0,msdos5'
	if [ x$feature_platform_search_hint = xy ]; then
	  search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos5 --hint-efi=hd0,msdos5 --hint-baremetal=ahci0,msdos5  893cb6a1-b7fb-40e6-a6b2-60027d573d84
	else
	  search --no-floppy --fs-uuid --set=root 893cb6a1-b7fb-40e6-a6b2-60027d573d84
	fi
	linux	/boot/vmlinuz-5.4.0-53-generic root=UUID=893cb6a1-b7fb-40e6-a6b2-60027d573d84 ro  quiet splash $vt_handoff
	initrd	/boot/initrd.img-5.4.0-53-generic
}
### END /etc/grub.d/48_linux_proxy ###