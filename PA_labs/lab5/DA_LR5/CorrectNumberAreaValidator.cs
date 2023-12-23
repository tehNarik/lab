namespace DA_LR5;

public class CorrectNumberAreaValidator: ValidatorBase
{
    public override Dictionary<string, string> HandleValidation(string input, int size)
    {
        int numbers = int.Parse(input);


            if (numbers < 1 || numbers > int.MaxValue)
        {
            ErrorsResult.Add("incorrect numbers",
                "you have entered incorrect numbers, they must be in the specified range without repetitions");
            return ErrorsResult;
        }
            
        if (Successor != null)
            return Successor.HandleValidation(input, size);

        return ErrorsResult;
    }
}