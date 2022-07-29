void Radixsort(int*data,int size) {
	Queue<int> q1, q2;
	for (int i = 0; i < sizeof(int) * 8; i++) {
		for (int j = 0; j < size; j++) {
			if ((data[j] >> i) & 1) {
				q2.push(data[j]);
			}
			else {
				q1.push(data[j]);
			}
		}
		int t = 0;
		while (!q1.is_empty()) {
			data[t++] = q1.front();
			q1.pop();
		}
		while (!q2.is_empty()) {
			data[t++] = q2.front();
			q2.pop();
		}
	}
}
