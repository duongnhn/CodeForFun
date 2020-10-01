import java.util.Calendar;
import java.util.GregorianCalendar;
import java.time.DayOfWeek;

public class DayOfWeekSolution {

    public static String getDay(String day, String month, String year) {
        Calendar calendar = new GregorianCalendar(Integer.parseInt(year), Integer.parseInt(month)-1,
        		Integer.parseInt(day)-1);
        DayOfWeek dayOfWeek = DayOfWeek.of(calendar.get(Calendar.DAY_OF_WEEK));
        return dayOfWeek.name();
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(getDay("05", "08", "2015"));
	}

}
