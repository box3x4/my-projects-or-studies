var fs = require('fs');

fs.readdir(process.argv[2], function(err,list){

	for(var i = 0;i<list.length;i++){

		var arr = list[i].split('.');

		if(arr.length-1 != 0)
			if(arr[arr.length-1] === process.argv[3])
				console.log(list[i]);
			
	}

});