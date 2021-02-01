#include <iostream>
#include <queue>

using namespace std;

struct PersonInfo {
	bool isJoined;
	int prevPerson;
	long long p;
	long long v;
};
struct PersonInfo pInfo[100002];

int main() {
	int n;
	long long t;
	typedef pair<long long, int> p;
	priority_queue<p, vector<p>, greater<p>> timeToMeetPerson;

	cin >> n >> t;
	int group = n;

	for (int i = 1; i < n + 1; i++) {
		cin >> pInfo[i].p >> pInfo[i].v;
		pInfo[i].prevPerson = i - 1;
	}

	for (int i = 1; i < n + 1; i++) {
		if (pInfo[i].v < pInfo[i - 1].v) {
			long long t = (pInfo[i].p - pInfo[i - 1].p) / (pInfo[i - 1].v - pInfo[i].v);
			if ((pInfo[i].p - pInfo[i - 1].p) % (pInfo[i - 1].v - pInfo[i].v) != 0)
				t++;
			timeToMeetPerson.push(make_pair(t, i));
		}
	}

	while (!timeToMeetPerson.empty()) {
		long long time = timeToMeetPerson.top().first;
		int personNum = timeToMeetPerson.top().second;
		timeToMeetPerson.pop();
		if (time > t)
			break;
		if (pInfo[personNum].isJoined)
		continue;
		else {
			int prevPersonNum = pInfo[personNum].prevPerson;
			int prevPrevPersonNum = pInfo[prevPersonNum].prevPerson;

			if (pInfo[personNum].v < pInfo[prevPrevPersonNum].v) {
				long long t = (pInfo[personNum].p - pInfo[prevPrevPersonNum].p) / (pInfo[prevPrevPersonNum].v - pInfo[personNum].v);
				if ((pInfo[personNum].p - pInfo[prevPrevPersonNum].p) % (pInfo[prevPrevPersonNum].v - pInfo[personNum].v) != 0)
					t++;
				timeToMeetPerson.push(make_pair(t, personNum));
			}
			pInfo[personNum].prevPerson = prevPrevPersonNum;
			pInfo[prevPersonNum].isJoined = true;
			group--;
		}
	}

	cout << group;

}