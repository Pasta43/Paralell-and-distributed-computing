#!/usr/bin/perl
#####################################
# Date: 2022-02-17
# Course: Parallel Computing
# Topic laboratory design and execution automation (mean and deviation)
#####################################

$PATH=`pwd`;
chomp($PATH);
#print($PATH);
#Number of repetition
$N =2;
#Vector of executables
@Executables=("bench01","bench02");
@Dimension=("100","200");
foreach $exe (@Executables){
	foreach $size (@Dimension){
		$File="$PATH/"."solutions/"."$exe"."-$size".".txt";
		#print"$File \n";
		for($i=0;$i<$N;$i++){
			system "$PATH/$exe $size >> $File";
			#print "$PATH/$exe $size\n";
		}
	}
	close($File);
}
