namespace DA_LR5;

public class SumNectarCalculator
{
    public double Culc(List<Item> items, List<int> randomItems)
    {
        double sum = 0;
        for (int i = 0; i < randomItems.Count; i++)
        {
            sum += items[randomItems[i]].Nectar();
        }

        return sum;
    }
}