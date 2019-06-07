#!/usr/bin/env bash

# THE DEFAULTS INITIALIZATION - OPTIONALS
_arg_ip_path=
_arg_top_rtl=
_arg_sim_driver=
_arg_net_driver=

# First step: create a destination dir
create_destination_dir_for () {
  dir_name=../$(basename $1)

  eval "${1}"

  if [ ! -d "$IP_PATH" ]; then
    echo "Error: IP path is not a directory. $1"
    exit 0
  fi

  if [ ! -d "$IP_PATH/hdl" ]; then
    echo "Error: IP director has no hdl folder. $1"
    exit 0
  fi

  if [ -d "$dir_name" ]; then
    read -p "$dir_name already exist, overwrite ? [Y/n]" answer
    if [ "$answer" == "Y" ] || [ "$answer" == "y" ]; then
      rm -rf $dir_name
    else
      echo "Cannot continue..."
      exit 0
    fi
  fi

  mkdir -p $dir_name/rtl
  mkdir -p $dir_name/sim
  mkdir -p $dir_name/tb
  mkdir -p $dir_name/sw

  cp -r $IP_PATH/hdl/* $dir_name/rtl/
  cp -r template/rtl/* $dir_name/rtl/
  cp -r template/sim/* $dir_name/sim/
  cp -r template/sw/* $dir_name/sw/
  cp -r template/tb/* $dir_name/tb/

  return 0;
}

# Second step: check if top exists
check_and_rtl_template () {

  dir_name=../$(basename $1)

  eval "${1}"
  eval "${2}"

  file_count=$(find $dir_name -name "$TOP_RTP" | wc -l)

  if [[ $file_count -ne 1 ]]; then
      echo "$TOP_RTP does not exist in $dir_name"
      exit 0
  fi

  # We now need to retrieve the module name to generate our testbench
  file_path=$(find $dir_name -name "$TOP_RTP")

  module_name=$(grep -r "module " $file_path | awk -F' ' '{print $2}')
  read -p "Found top module name : $module_name, correct ? [Y/n]" answer
  if [ "$answer" == "Y" ] || [ "$answer" == "y" ]; then
    sed "s/@TOP_MODULE_NAME@/${module_name}/g" $dir_name/rtl/tb_axi_lite_slave.v  > /dev/null 2>&1
  else
    echo "Cannot continue..."
    exit 0
  fi

  return 0;
}

# Third step: check if sim driver exist
check_if_sim_driver_exist () {
  eval "${1}"

  file_count=$(find ../system/lib -name "$SIM_DRIVER.cpp" | wc -l)
  if [[ $file_count -ne 1 ]]; then
      echo "$SIM_DRIVER is not a valid simulator driver! Please check ../system/lib/sim_driver for valid file"
      exit 0
  fi

  return 0;
}

# Fourth step: check if net driver exist
check_if_net_driver_exist () {
  eval "${1}"

  echo $NET_DRIVER

  file_count=$(find ../system/lib -name "$NET_DRIVER.cpp" | wc -l)
  if [[ $file_count -ne 1 ]]; then
      echo "$NET_DRIVER is not a valid simulator driver! Please check ../system/lib/net for valid file"
      exit 0
  fi

  return 0;
}

# Finally, create main.cpp file
create_main_file () {
  return 0;
}

die()
{
	local _ret=$2
	test -n "$_ret" || _ret=1
	test "$_PRINT_HELP" = yes && print_help >&2
	echo "$1" >&2
	exit ${_ret}
}

begins_with_short_option()
{
	local first_option all_short_options
	all_short_options='h'
	first_option="${1:0:1}"
	test "$all_short_options" = "${all_short_options/$first_option/}" && return 1 || return 0
}



# THE DEFAULTS INITIALIZATION - POSITIONALS
_positionals=()
# THE DEFAULTS INITIALIZATION - OPTIONALS

print_help ()
{
	printf '%s\n' "IP_PATH=<> TOP_RTL=<> SIM_DRIVER=<> NET_DRIVER=<>"
	printf 'Usage: %s [-h|--help] <IP_PATH> <TOP_RTL> <SIM_DRIVER> <NET_DRIVER>\n' "$0"
	printf '\t%s\n' "<IP_PATH>: Target IP Path"
	printf '\t%s\n' "<TOP_RTL>: RTL TOP file"
	printf '\t%s\n' "<SIM_DRIVER>: Simulation driver name"
	printf '\t%s\n' "<NET_DRIVER>: Net driver name"
	printf '\t%s\n' "-h,--help: Prints help"
}

parse_commandline ()
{
	while test $# -gt 0
	do
		_key="$1"
		case "$_key" in
			-h|--help)
				print_help
				exit 0
				;;
			-h*)
				print_help
				exit 0
				;;
			*)
				_positionals+=("$1")
				;;
		esac
		shift
	done
}


handle_passed_args_count ()
{
	_required_args_string="'IP_PATH', 'TOP_RTL', 'SIM_DRIVER' and 'NET_DRIVER'"
	test ${#_positionals[@]} -ge 4 || _PRINT_HELP=yes die "FATAL ERROR: Not enough positional arguments - we require exactly 4 (namely: $_required_args_string), but got only ${#_positionals[@]}." 1
	test ${#_positionals[@]} -le 4 || _PRINT_HELP=yes die "FATAL ERROR: There were spurious positional arguments --- we expect exactly 4 (namely: $_required_args_string), but got ${#_positionals[@]} (the last one was: '${_positionals[*]: -1}')." 1
}

assign_positional_args ()
{
	_positional_names=('_arg_ip_path' '_arg_top_rtl' '_arg_sim_driver' '_arg_net_driver' )

	for (( ii = 0; ii < ${#_positionals[@]}; ii++))
	do
		eval "${_positional_names[ii]}=\${_positionals[ii]}" || die "Error during argument parsing, possibly an Argbash bug." 1
	done
}


echo "Author : Corteggiani Nassim"
echo "Company: EURECOM"
echo "Contact: corteggi@eurecom.fr"
echo "Status : beta"

echo "######################################################"
echo "Brief: Automated IP Integrator"
echo "######################################################"

# Parse arguments
parse_commandline "$@"
handle_passed_args_count
assign_positional_args

echo "Value of positional-arg: $_arg_ip_path"
echo "Value of positional-arg: $_arg_top_rtl"
echo "Value of positional-arg: $_arg_sim_driver"
echo "Value of positional-arg: $_arg_net_driver"

# First step: create a destination dir
create_destination_dir_for $_arg_ip_path

# Second step: check if top exists
check_and_rtl_template $_arg_ip_path $_arg_top_rtl

# Third step: check if sim driver exist
check_if_sim_driver_exist $_arg_sim_driver

# Fourth step: check if net driver exist
check_if_net_driver_exist $_arg_net_driver

# Finally, create main.cpp file
create_main_file $SIM_DRIVER $NET_DRIVER

echo "Done!"
