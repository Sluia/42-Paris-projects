#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// how to compile with threads:
// => gcc <args> <program> -lpthread

typedef struct s_node
{
	pthread_t th_philo;
	int id;
	suseconds_t time_last_meal;
	int meals_eaten;
	void *st_data;
	struct s_node *next;
} t_node;

typedef struct s_data
{
	pthread_t th_time;
	//pthread_mutex_t mutex_time;
	pthread_t th_death_status;
	struct timeval time;
	suseconds_t time_elapsed;
	t_node *philos;
	pthread_mutex_t *mutex_forks;
	int *fork_status;
	int death_status;
	int nb_philos;
	int time_die;
	int time_eat;
	int time_sleep;
	int must_eat_nb;
} t_data;

void init_pars(t_data *info);
int init_philos(t_data *info);

t_node *new_node(int id, t_data *info);
void add_node_front(t_node **philos, t_node *new);
void add_node_back(t_node **philos, t_node *new);
t_node *get_node_wpos(t_node *philos, int pos);
int get_list_length(t_node *philos);

void loop_philo(t_data *info);
void *routine_philo(void *th_arg);
void try_eating(t_data *info, int philo_id);
int pick_fork(t_data *info, int fork_id, int philo_id);
void *check_deaths(void *th_arg);
int write_event(suseconds_t time_elapsed, int id_event, int id_philo);

int parsing(t_data *info, int argc, char **argv);
int only_digit(char *str);
void set_pars_values(t_data *info, int nb, int i);
int valid_values(t_data *info);

void *update_time(void *th_arg);

long ft_atoi(const char *str);
char *ft_itoa(long nb);
int get_nb_length(long nb, int base_length);
int ft_isdigit(int c);
int ft_strlen(const char *str);
void *ft_calloc(int nb_elem, int size);
void *ft_memset(void *ptr, int c, int n);
int ft_strcmp(char *str1, char *str2);
void ft_wrstr_nl(int fd, char *str);
char *ft_strjoin_philo(char *str1, char *str2, char *str3, char *str4);
char *ft_strdup(char *str, int length);
char *ft_strcpy(char *dest, char *src);
char *ft_strcat(char *dest, char *src);

#endif