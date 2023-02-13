#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <glib.h>
#include <locale.h>

// Make them global

GtkWidget	*window;
GtkWidget	*fixed1;
GtkWidget	*serviceSource;
GtkWidget	*serviceValue;
GtkWidget	*radioDiscount7;
GtkWidget	*radioDiscount10;
GtkWidget	*radioDiscount12;
GtkWidget	*radioCut30;
GtkWidget	*radioCut35;
GtkWidget	*radioCut40;
GtkWidget	*btnExit;
GtkWidget	*serviceBoosterCut;
GtkWidget	*serviceBoosterNote;
GtkWidget	*serviceResult;
GtkWidget	*radioPlatformSherpa;
GtkWidget	*radioPlatformXBOX;
GtkWidget	*radioPlatformPS4;
GtkWidget	*radioPlatformPC;
GtkWidget	*serviceSourceName;
GtkBuilder	*builder; 

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("calc2.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	

        gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	serviceSource = GTK_WIDGET(gtk_builder_get_object(builder, "serviceSource"));
	serviceValue = GTK_WIDGET(gtk_builder_get_object(builder, "serviceValue"));
	radioDiscount7 = GTK_WIDGET(gtk_builder_get_object(builder, "radioDiscount7"));
	radioDiscount10 = GTK_WIDGET(gtk_builder_get_object(builder, "radioDiscount10"));
	radioDiscount12 = GTK_WIDGET(gtk_builder_get_object(builder, "radioDiscount12"));
	radioCut30 = GTK_WIDGET(gtk_builder_get_object(builder, "radioCut30"));
	radioCut35 = GTK_WIDGET(gtk_builder_get_object(builder, "radioCut35"));
	radioCut40 = GTK_WIDGET(gtk_builder_get_object(builder, "radioCut40"));
	btnExit = GTK_WIDGET(gtk_builder_get_object(builder, "btnExit"));
	serviceBoosterCut = GTK_WIDGET(gtk_builder_get_object(builder, "serviceBoosterCut"));
	serviceBoosterNote = GTK_WIDGET(gtk_builder_get_object(builder, "serviceBoosterNote"));
	serviceResult = GTK_WIDGET(gtk_builder_get_object(builder, "serviceResult"));
	radioPlatformSherpa = GTK_WIDGET(gtk_builder_get_object(builder, "radioPlatformSherpa"));
	radioPlatformXBOX = GTK_WIDGET(gtk_builder_get_object(builder, "radioPlatformXBOX"));
	radioPlatformPS4 = GTK_WIDGET(gtk_builder_get_object(builder, "radioPlatformPS4"));
	radioPlatformPC = GTK_WIDGET(gtk_builder_get_object(builder, "radioPlatformPC"));
	serviceSourceName = GTK_WIDGET(gtk_builder_get_object(builder, "serviceSourceName"));

	gtk_widget_show(window);

	gtk_main();

	return EXIT_SUCCESS;
	}

void on_serviceSource_changed(GtkEntry *entry) {

	const gchar *text = gtk_entry_get_text(entry);
	double value = g_ascii_strtod(text, NULL);
	double cutvalue = g_ascii_strtod(text, NULL);
	double discount = 0;
	double cutp = 0;

	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioCut30))) {
	cutp = 0.7;
   }    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioCut35))) {
	cutp = 0.65;
   }    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioCut40))) {
	cutp = 0.60;
}

	

	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioDiscount7))) {
	discount = 0.07;
   }    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioDiscount10))) {
	discount = 0.1;
   }    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioDiscount12))) {
	discount = 0.12;
}
		
	value = value - value * discount;
	
	gchar result[100];

	setlocale(LC_ALL, "");
	snprintf(result, 100, "€%.2lf", value);
	gtk_label_set_text(GTK_LABEL(serviceResult), result);
	
	
	cutvalue = value - value * cutp;


	

	
	gchar cutresult[100];

	setlocale(LC_ALL, "");
	snprintf(cutresult, 100, "€%.2lf", cutvalue);
	gtk_label_set_text(GTK_LABEL(serviceBoosterCut), cutresult);
}

void on_radioDiscount7_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) {
		on_serviceSource_changed(GTK_ENTRY(serviceSource));
	}
}
	
void on_radioDiscount10_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) {
		on_serviceSource_changed(GTK_ENTRY(serviceSource));
	}
}
	
void on_radioDiscount12_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) {
		on_serviceSource_changed(GTK_ENTRY(serviceSource));
	}
}

void on_radioCut30_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) {
		on_serviceSource_changed(GTK_ENTRY(serviceSource));
	}
}

void on_radioCut35_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) {
		on_serviceSource_changed(GTK_ENTRY(serviceSource));
	}
}

void on_radioCut40_toggled(GtkRadioButton *b) {
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) {
		on_serviceSource_changed(GTK_ENTRY(serviceSource));
	}
}


void on_serviceSourceName_changed(GtkEntry *entry2) {
	const gchar *text2 = gtk_entry_get_text(entry2);
	double value2 = g_ascii_strtod(text2, NULL);
	gchar *gplat = "X"; 

	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioPlatformSherpa))) {
		gplat = "Sherpa";
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioPlatformXBOX))) {
		gplat = "XBOX";
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioPlatformPC))) {
		gplat = "PC";
	} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioPlatformPS4))) {
		gplat = "PS4";
	}

	gchar result2[100];
	setlocale(LC_ALL, "");
	snprintf(result2, 100, "€%.2lf", value2);
	gtk_label_set_text(GTK_LABEL(serviceBoosterNote), result2);
}

	
void on_btnExit_clicked (GtkButton *b) {
gtk_main_quit();

}












