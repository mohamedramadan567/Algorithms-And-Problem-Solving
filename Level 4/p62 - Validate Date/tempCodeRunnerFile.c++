bool IsValideDate(sDate Date1)
{
    return ((Date1.Day >= 1 && Date1.Day <= NumberOfDaysInAMonth(Date1.Year, Date1.Month)) && Date1.Month >= 1 && Date1.Month <= 12);
}
