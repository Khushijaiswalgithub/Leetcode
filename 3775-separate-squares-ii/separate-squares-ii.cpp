class Solution {
public:
    struct Event {
        long long y, x1, x2;
        int type; 
    };

    double unionWidth(vector<pair<long long,long long>>& segs) {
        if (segs.empty()) return 0.0;
        sort(segs.begin(), segs.end());

        long long sum = 0;
        long long L = segs[0].first, R = segs[0].second;

        for (int i = 1; i < segs.size(); i++) {
            if (segs[i].first > R) {
                sum += R - L;
                L = segs[i].first;
                R = segs[i].second;
            } else {
                R = max(R, segs[i].second);
            }
        }
        sum += R - L;
        return (double)sum;
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        for (auto &s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});
        }

        sort(events.begin(), events.end(),
             [](const Event &a, const Event &b) {
                 return a.y < b.y;
             });

        vector<pair<long long,long long>> active;
        double totalArea = 0.0;
        for (int i = 0; i + 1 < events.size(); ) {
            long long curY = events[i].y;

            while (i < events.size() && events[i].y == curY) {
                if (events[i].type == +1)
                    active.push_back({events[i].x1, events[i].x2});
                else {
                    for (int k = 0; k < active.size(); k++) {
                        if (active[k].first == events[i].x1 &&
                            active[k].second == events[i].x2) {
                            active.erase(active.begin() + k);
                            break;
                        }
                    }
                }
                i++;
            }

            if (i == events.size()) break;

            double w = unionWidth(active);
            double h = events[i].y - curY;
            totalArea += w * h;
        }

        double target = totalArea / 2.0;
        double acc = 0.0;
        active.clear();
        for (int i = 0; i + 1 < events.size(); ) {
            long long curY = events[i].y;

            while (i < events.size() && events[i].y == curY) {
                if (events[i].type == +1)
                    active.push_back({events[i].x1, events[i].x2});
                else {
                    for (int k = 0; k < active.size(); k++) {
                        if (active[k].first == events[i].x1 &&
                            active[k].second == events[i].x2) {
                            active.erase(active.begin() + k);
                            break;
                        }
                    }
                }
                i++;
            }

            if (i == events.size()) break;

            double w = unionWidth(active);
            double h = events[i].y - curY;
            double area = w * h;

            if (acc + area >= target) {
                return curY + (target - acc) / w;
            }
            acc += area;
        }

        return 0.0;
    }
};
