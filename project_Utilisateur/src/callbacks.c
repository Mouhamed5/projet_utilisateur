#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"

utilisateur ut;
void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj_utilisateur, *dashboard_utilisateur;


dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");

//gtk_widget_destroy(dashboard_hebergement);
aj_utilisateur=lookup_widget(objet,"aj_utilisateur");
aj_utilisateur=create_aj_utilisateur();

gtk_widget_show(aj_utilisateur);
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod_utilisateur, *dashboard_utilisateur;


dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");

//gtk_widget_destroy(dashboard_hebergement);
mod_utilisateur=lookup_widget(objet,"mod_utilisateur");
mod_utilisateur=create_mod_utilisateur();

gtk_widget_show(mod_utilisateur);
}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_utilisateur, *dashboard_utilisateur;


dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");

//gtk_widget_destroy(dashboard_hebergement);
af_utilisateur=lookup_widget(objet,"af_utilisateur");
af_utilisateur=create_af_utilisateur();

gtk_widget_show(af_utilisateur);

treeview=lookup_widget(af_utilisateur,"treeview_utilisateur");

afficher_utilisateur(treeview,"utilisateur.txt");
}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *alarme, *dashboard_utilisateur;
dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
alarme=lookup_widget(objet,"alarme");
alarme=create_alarme();
gtk_widget_show(alarme);
treeview=lookup_widget(alarme,"treeview_alarme");
afficher_alarme(treeview,"alarme.txt");
}





                               
void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *recherche, *dashboard_utilisateur;


dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");

//gtk_widget_destroy(dashboard_utilisateur);
recherche=lookup_widget(objet,"recherche");
recherche=create_recherche();

gtk_widget_show(recherche);
}


void
on_button_alarme_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *alarme;
alarme=lookup_widget(objet,"alarme");
gtk_widget_destroy(alarme);
alarme=lookup_widget(objet,"alarme");
alarme=create_alarme();
gtk_widget_show(alarme);
treeview=lookup_widget(alarme,"treeview_alarme");
afficher_alarme(treeview,"alarme.txt");
}




void
on_button9_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *af_utilisateur, *dashboard_utilisateur;
af_utilisateur=lookup_widget(objet,"af_utilisateur");
gtk_widget_destroy(af_utilisateur);
dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
dashboard_utilisateur=create_dashboard_utilisateur();
gtk_widget_show(dashboard_utilisateur);
}



void
on_button14_ajout_k_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *af_utilisateur, *aj_utilisateur;
af_utilisateur=lookup_widget(objet,"af_utilisateur");
gtk_widget_destroy(af_utilisateur);
aj_utilisateur=lookup_widget(objet,"aj_utilisateur");
aj_utilisateur=create_aj_utilisateur();
gtk_widget_show(aj_utilisateur);
}


void
on_button12_modifier_k_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *af_utilisateur, *mod_utilisateur;
af_utilisateur=lookup_widget(objet,"af_utilisateur");
gtk_widget_destroy(af_utilisateur);
mod_utilisateur=lookup_widget(objet,"mod_utilisateur");
mod_utilisateur=create_mod_utilisateur();
gtk_widget_show(mod_utilisateur);
}


void
on_button13_recherche_k_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *af_utilisateur, *recherche;
af_utilisateur=lookup_widget(objet,"af_utilisateur");
gtk_widget_destroy(af_utilisateur);
recherche=lookup_widget(objet,"recherche");
recherche=create_recherche();
gtk_widget_show(recherche);
}


void
on_button10_supprimer_k_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo;
	//GtkTreeModel *model=gtk_tree_view_get_model(treeview);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet utilisateur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer_utilisateur(ut,"utilisateur.txt");
	//afficher_utilisateur(treeview,"utilisateur.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}
}


void
on_button15_mouv_k_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *af_utilisateur, *alarme;
af_utilisateur=lookup_widget(objet,"af_utilisateur");
gtk_widget_destroy(af_utilisateur);
alarme=lookup_widget(objet,"alarme");
alarme=create_alarme();
gtk_widget_show(alarme);
}


void
on_button_af_k_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_utilisateur;
af_utilisateur=lookup_widget(objet,"af_utilisateur");
gtk_widget_destroy(af_utilisateur);
af_utilisateur=lookup_widget(objet,"af_utilisateur");
af_utilisateur=create_af_utilisateur();
gtk_widget_show(af_utilisateur);
treeview=lookup_widget(af_utilisateur,"treeview_utilisateur");
afficher_utilisateur(treeview,"utilisateur.txt");
}



void
on_treeview_utilisateur_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gint id;
	utilisateur u;
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	ut.id=id;
	
}
}


void
on_button6_k_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj_utilisateur, *af_utilisateur;
aj_utilisateur=lookup_widget(objet,"aj_utilisateur");
gtk_widget_destroy(aj_utilisateur);
af_utilisateur=lookup_widget(objet,"af_utilisateur");
af_utilisateur=create_af_utilisateur();
gtk_widget_show(af_utilisateur);
}


void
on_button_valide_k_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1_k, *aj2_k, *aj3_k, *aj4_k, *aj5_k, *aj6_k, *homme_k, *femme_k;
GtkCalendar *ajc_k;
utilisateur u;
guint day, month, year;
aj1_k=lookup_widget(objet,"aj1_k");
aj2_k=lookup_widget(objet,"aj2_k");
aj3_k=lookup_widget(objet,"aj3_k");
ajc_k=lookup_widget(objet,"ajc_k");
homme_k=lookup_widget(objet,"homme_k");
femme_k=lookup_widget(objet,"femme_k");
aj4_k=lookup_widget(objet,"aj4_k");
aj5_k=lookup_widget(objet,"aj5_k");
aj6_k=lookup_widget(objet,"aj6_k");
u.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aj1_k));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(aj3_k)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(aj4_k)));
strcpy(u.email,gtk_entry_get_text(GTK_ENTRY(aj5_k)));
u.sexe=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(homme_k))?0:1;
gtk_calendar_get_date(GTK_CALENDAR(ajc_k), &day, &month, &year);
u.d.j=year;
u.d.m=month+1;
u.d.a=day;
u.role = gtk_combo_box_get_active(GTK_COMBO_BOX(aj2_k))+1;
u.nv = u.role==6?gtk_combo_box_get_active(GTK_COMBO_BOX(aj6_k))+1:0;
ajouter_utilisateur(u,"utilisateur.txt");

}


void
on_check_id_k_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1_k, *mod2_k, *mod3_k, *mod4_k, *mod5_k, *mod6_k, *pInfo;
utilisateur p;
int a=0;
char ch[20];
FILE *f;
mod1_k=lookup_widget(objet,"mod1_k");
mod2_k=lookup_widget(objet,"mod2_k");
mod3_k=lookup_widget(objet,"mod3_k");
mod4_k=lookup_widget(objet,"mod4_k");
mod5_k=lookup_widget(objet,"mod5_k");
mod6_k=lookup_widget(objet,"mod6_k");
int id = atoi(gtk_entry_get_text(GTK_ENTRY(mod1_k)));
f = fopen("utilisateur.txt","r");
if(f!=NULL){
while(fscanf(f,"%d %d %s %s %s %d %d %d %d %d\n",&(p.id),&(p.role),p.prenom,p.nom,p.email,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),&(p.nv))!=EOF)
	{
		if(p.id==id){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_combo_box_set_active(GTK_COMBO_BOX(mod2_k),p.role-1);
gtk_entry_set_text(GTK_ENTRY(mod3_k),p.prenom);
gtk_entry_set_text(GTK_ENTRY(mod4_k),p.nom);
gtk_entry_set_text(GTK_ENTRY(mod5_k),p.email);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod6_k),p.nv-1);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Utilisateur introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_modvalid_k_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1_k, *mod2_k, *mod3_k, *mod4_k, *mod5_k, *mod6_k, *pInfo;
utilisateur u;
int c;
mod1_k=lookup_widget(objet,"mod1_k");
mod2_k=lookup_widget(objet,"mod2_k");
mod3_k=lookup_widget(objet,"mod3_k");
mod4_k=lookup_widget(objet,"mod4_k");
mod5_k=lookup_widget(objet,"mod5_k");
mod6_k=lookup_widget(objet,"mod6_k");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod1_k)));
u.role = gtk_combo_box_get_active(GTK_COMBO_BOX(mod2_k))+1;
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(mod3_k)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(mod4_k)));
strcpy(u.email,gtk_entry_get_text(GTK_ENTRY(mod5_k)));
u.nv = gtk_combo_box_get_active(GTK_COMBO_BOX(mod6_k))+1;
modifier_utilisateur(u,"utilisateur.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Utilisateur modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_button8_k_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod_utilisateur, *af_utilisateur;
mod_utilisateur=lookup_widget(objet,"mod_utilisateur");
gtk_widget_destroy(mod_utilisateur);
af_utilisateur=lookup_widget(objet,"af_utilisateur");
af_utilisateur=create_af_utilisateur();
gtk_widget_show(af_utilisateur);
}


void
on_chercher_k_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *r1_k, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *pInfo;
char date_naissance[20], sexe[20], role[30], niveau[20];
r1_k=lookup_widget(objet,"r1_k");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
r7=lookup_widget(objet,"r7");
r8=lookup_widget(objet,"r8");
int id = atoi(gtk_entry_get_text(GTK_ENTRY(r1_k)));
utilisateur p = chercher_utilisateur(id,"utilisateur.txt");
if (p.id==-1){
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"ID introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
else{
sprintf(role,p.role==1?"Admin":p.role==2?"Technicien":p.role==3?"Responsable réclamations":p.role==4?"Agent de foyer":p.role==5?"Agent de restaurant":"Etudiant");
gtk_label_set_text(GTK_LABEL(r2),role);
gtk_label_set_text(GTK_LABEL(r3),p.prenom);
gtk_label_set_text(GTK_LABEL(r4),p.nom);
gtk_label_set_text(GTK_LABEL(r5),p.email);
sprintf(sexe,p.sexe==0?"Homme":"Femme");
gtk_label_set_text(GTK_LABEL(r6),sexe);
sprintf(date_naissance,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
gtk_label_set_text(GTK_LABEL(r7),date_naissance);
sprintf(niveau,p.role==6?(p.nv==1?"1ère année":"%déme année"):"Employé",p.nv);
gtk_label_set_text(GTK_LABEL(r8),niveau);
}
}


void
on_button7_k_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *recherche, *af_utilisateur;
recherche=lookup_widget(objet,"recherche");
gtk_widget_destroy(recherche);
af_utilisateur=lookup_widget(objet,"af_utilisateur");
af_utilisateur=create_af_utilisateur();
gtk_widget_show(af_utilisateur);
}


