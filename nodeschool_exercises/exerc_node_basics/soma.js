var sum = 0;
var i = 2;

while(true){
	if(typeof process.argv[i] != 'undefined'){
		sum += Number(process.argv[i]);
	}
	else{
		break;
	}

	i++;
}

console.log(sum);