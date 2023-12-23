namespace DA_LR5;

public class HiveInput
{
    public Hive newHive()
    {
        ErrorsWriters errorsWriter = new ErrorsWriters();
        MassageWriter.Write(Massages.InputHive);

        bool correctEnter = false;
        string input = string.Empty;
        while (!correctEnter)
        {
            input = Console.ReadLine() ?? string.Empty;
            Dictionary<string, string> errors = InputHiveValidationContext.Validate(input, 2);
            if (errors.Count != 0)
            {
                errorsWriter.Write(errors);
                MassageWriter.Write(Massages.TryAgain);
                MassageWriter.Write(Massages.InputHive);
            }
            else
                correctEnter = true;
        }

        return new Hive(input);
    }
}