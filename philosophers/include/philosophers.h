#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_node
{
	pthread_t th_philo;
	int id;
	suseconds_t time_last_meal;
	int meals_eaten;
	void *info;
	struct s_node *next;
} t_node;

typedef struct s_data
{
	struct timeval time;
	suseconds_t start_time;
	t_node *philos;
	pthread_t th_death_status;
	pthread_mutex_t *mutex_forks;
	pthread_mutex_t mutex_nb_done_eating;
	pthread_mutex_t mutex_write;
	int death_status;
	int nb_philos;
	int time_die;
	int time_eat;
	int time_sleep;
	int must_eat_nb;
	int nb_done_eating;
} t_data;

void *check_deaths(void *th_arg);

void free_all(t_data *info);
void free_list(t_node *philos);

void init_info(t_data *info);
int init_philos(t_data *info);

t_node *new_node(int id, t_data *info);
void add_node_front(t_node **philos, t_node *new);
void add_node_back(t_node **philos, t_node *new);
t_node *get_node_wpos(t_node *philos, int pos);
int get_list_length(t_node *philos);

int loop_philo(t_data *info);
void launch_philo_threads(t_node *philos, int even);
void close_philo_threads(t_node *philos);
void *routine_philo(void *th_arg);
void try_eating(t_data *info, t_node *philo);

void init_mutex(t_data *info);
void destroy_mutex(t_data *info);

int write_event(t_data *info, int id_event, int id_philo);
char *get_str_event(int id_event, char *itoa_time, char *itoa_id);

int parsing(t_data *info, int argc, char **argv);
int only_digit(char *str);
void set_info_values(t_data *info, int nb, int i);
int valid_values(t_data *info);

suseconds_t get_elapsed_time(t_data *info);
void ft_usleep(suseconds_t duration, t_data *info);

int ft_strlen(const char *str);
int ft_strcmp(char *str1, char *str2);
char *ft_strdup(char *str, int length);
char *ft_strcpy(char *dest, char *src);
char *ft_strcat(char *dest, char *src);

int ft_isdigit(int c);
void *ft_calloc(int nb_elem, int size);
void *ft_memset(void *ptr, int c, int n);
void ft_wrstr_nl(int fd, char *str);
char *ft_strjoin_philo(char *str1, char *str2, char *str3, char *str4);

long ft_atoi(const char *str);
char *ft_itoa(long nb);
int get_nb_length(long nb, int base_length);

#endif