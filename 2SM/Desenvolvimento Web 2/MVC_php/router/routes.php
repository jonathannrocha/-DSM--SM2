<?php

$routes = [
    '/' => 'HomeController@index',
    '/user' => 'UserController@index',
    '/user/{id}' => 'UserController@show',
    '/cadastro' => 'CadastroController@index'
];