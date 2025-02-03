const findRepeatedDnaSequences = (s) => {
    const frequency = {};
    for (let i = 0; i <= s.length-10; i++) {
		const sequence = s.substr(i, 10);
		frequency[sequence] = ~~frequency[sequence] + 1;
	}
	return Object.keys(frequency).filter(v => frequency[v] > 1);
};