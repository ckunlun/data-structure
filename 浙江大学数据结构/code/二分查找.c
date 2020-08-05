Position BinarySearch(List L, ElementType X)
{
    Position cur = 0, p = 0;//记录当前的位置
    Position start = 1, end = L->Last;
    cur = end / 2;
    while (start <= end)//zhu yi tui chu tiao jian
    {
        if (L->Data[cur] > X)
        {
            end = cur - 1;
        }
        else if (L->Data[cur] < X)
        {
            start = cur + 1;
        }
        else if (L->Data[cur] == X)
        {
            p = cur;
            break;
        }
        cur = (start + end) / 2;// zhu yi gen xing fang shi
    }

    if (p != 0)
        return p;
    else
        return NotFound;

}