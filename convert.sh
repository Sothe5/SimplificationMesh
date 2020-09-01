for model in models/directededges/*.diredge
	do
	echo "Processing ${model}"
	filename=${model##*/}
	echo "Filename: $filename"
 	namebase=${filename%.diredge}
	echo "Namebase: $namebase"
	outname=models/diredgenormals/${namebase}.diredgenormal
	echo "Output:   $outname"
	./SimplificationSolution $model $outname
	done
