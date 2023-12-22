namespace DA_LR5;

public class MaxItemFinder
{
    public int Find(List<int> distribution)
    {
        int max = 0;
        int maxIndex = 0;
        for (int i = 0; i < distribution.Count; i++)
        {
            if (distribution[i] > max)
            {
                max = distribution[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }
}