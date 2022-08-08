vector<Event> tr[MAXT << 1];
#define MYZ int m = l + (r - l) / 2, \
    y = o + 1, z = o + (r - l) / 2 * 2
void insert_event(int o, int l, int r, int ql, int qr, Event e) {
    if (r <= ql or  qr <= l) return;
    if (ql <= l and r <= qr)
        return tr[o].push_back(e), void();
    MYZ;
    insert_event(y, l, m, ql, qr, e);
    insert_event(z, m, r, ql, qr, e);
}
void traversal(int o, int l, int r) {
    int cnt = 0;
    for (auto e : tr[o])
        if (do_things(e))
            cnt++;
    if (l == r-1) // record ans
    else {
        MYZ;
        traversal(y, l, m);
        traversal(z, m, r);
    }
    while (cnt--) undo();
}
