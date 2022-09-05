struct Meta {
    static Meta Null;
    size_t rank;
    ll sum[2];
    Meta(size_t _r = 0): rank(_r), sum{ 0, 0 } {}
} Meta::Null;

#define getMeta(it) ({ \
    auto _it = (it); \
    (_it == end) ? Meta::Null : _it.get_metadata(); \
})
#define PB_DS_CLASS_T_DEC \
    template<typename Node_CItr, typename Node_Itr, typename Cmp_Fn, typename _Alloc>
#define PB_DS_CLASS_C_DEC \
    node_update<Node_CItr, Node_Itr, Cmp_Fn, _Alloc>

template<typename Node_CItr, typename Node_Itr, typename Cmp_Fn, typename _Alloc>
class node_update {
public:
    using metadata_type = Meta;
    inline ll sum(int i) const;
private:
    virtual Node_CItr node_begin() const = 0;
    virtual Node_CItr node_end() const = 0;
protected:
    node_update() {}
    inline void operator()(Node_Itr it, Node_CItr end) const {
        const auto l_meta = getMeta(it.get_l_child());
        const auto r_meta = getMeta(it.get_r_child());
        auto& meta = const_cast<Meta&>(it.get_metadata());
        auto val = *(*it);
        meta.rank = 1 + l_meta.rank + r_meta.rank;
        meta.sum[0] = l_meta.sum[0] + val;
        meta.sum[1] = r_meta.sum[0] + val;
    }
};

PB_DS_CLASS_T_DEC inline ll PB_DS_CLASS_C_DEC::
sum(int i) const {
    auto it = node_begin();
    auto end = node_end();
    if (it == end) return 0;
    return it.get_metadata().sum[i];
}

template<typename T, typename U = null_type>
using rkt = tree<T, U, less<T>, rb_tree_tag, node_update>;
