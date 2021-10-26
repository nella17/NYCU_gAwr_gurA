vector<Event> tr[MAXT << 2];
void insert_event(int o, int l, int r, int ql, int qr, Event e) {
    if (ql <= l && r <= qr)
        return tr[o].push_back(e), void();
    int m = l + (r - l) / 2;
    int y = o+1;
    int z = o + (r - l) / 2 * 2;
    if (qr < m)
        insert_event(y, l, m, ql, qr, e);
    else if (m <= ql)
        insert_event(z, m, r, ql, qr, e);
    else {
        insert_event(y, l, m, ql, qr, e);
        insert_event(z, m, r, ql, qr, e);
    }
}
void traversal(int o, int l, int r) {
    int cnt = 0;
    for (auto e : tr[o])
        if (do_things(e))
            cnt++;
    if (lb == rb) // record ans
    else {
        int m = l + (r - l) / 2;
        int y = o+1;
        int z = o + (r - l) / 2 * 2;
        traversal(y, l, m);
        traversal(z, m, r);
    }
    while (cnt--) undo();
}
