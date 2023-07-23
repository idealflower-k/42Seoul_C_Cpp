/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:22:35 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/23 19:47:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// ERROR
	// cd 잘못된 인수 ("error: cd: bad arguments\n")
	// cd 실패 ("error: cd: cannot change directory to (path_to_change(cd에 대한 인수로 대체))\n")
	// execve 실패 ("error: cannot execute (executable_that_failed(실행파일 경로))\n")
	// 시스템 호출 에러 ("error: fatal\n") 프로그램 종료!

// parser , '|', ';'
// cmd_arr, pipe, list, cd(chdir)
// error, leaks

// cmd_arr
	// cmd, option....
// pipe
	// int[2];
// list (;을 기준으로 나누어진 cmd_list를 담는다.)
	// cmd_list (|로 연결된 명령어 처리)
		// type, cmd_arr, pipe

//parser
	// head_list를 만든다.
	// 하위 cmd_list를 만든다.
	// cmd_list안에 있는 명령어의 수
		// cmd를 넣고 | 까지 옵션으로 넣는다.
		// ; 또는 null까지 next로 연결
	// ; 이 나오면 head_list 의 next를 만들고 하위 cmd_list 작업

// 살행
	// 첫번째 명령어 pipe[0] = stdin, pipe[1] = stdout
	// 중간 명령어 pipe[0] = 이전 pipe[1], pipe[1] = stdout
	// 마지막 명령어 pipe[0] = 이전 pipe[1], pipe[1] = stdout
	// head_list를 순회하면서 cmd_list 순회 실행
	// cd 는 따로 처리하기
	// 에러 처리

typedef struct s_list t_list;
typedef struct s_cmd t_cmd;

struct s_list {
	struct cmd		*cmd_list;
	int				num_cmd;
	struct s_list	*next;
};

struct s_cmd {
	char	**cmd_arr;
	int		pipe[2];
	struct cmd* next;
};

#endif
