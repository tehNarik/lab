namespace DA_LR5;

public class UserInputItems
{
    public List<Item> Input(int numItem)
    {
        ErrorsWriters errorsWriter = new ErrorsWriters();
        MassageWriter.WriteArg(Massages.UserInputItems, numItem);

        List<Item> items = new List<Item>();
        for (int i = 0; i < numItem; i++)
        {
            bool correctEnter = false;
            string input = string.Empty;
            while (!correctEnter)
            {
                MassageWriter.WriteArgNoEnter(Massages.Item, (i + 1));
                input = Console.ReadLine() ?? string.Empty;
                Dictionary<string, string> errors = InputItemValidationContext.Validate(input, 2);
                if (errors.Count != 0)
                {
                    errorsWriter.Write(errors);
                    MassageWriter.Write(Massages.TryAgain);
                    MassageWriter.WriteArg(Massages.UserInputItems, numItem);
                }
                else
                {
                    items.Add(new Item(input));
                    correctEnter = true;
                }
                    
            }
        }

        return items;
    }
}